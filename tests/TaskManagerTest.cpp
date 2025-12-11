#include <gtest/gtest.h>
#include "../src/TaskManager.h"

TEST(TaskManagerTest, ParseCompletedTask) {
    TaskManager tm;
    string line = "Fare la spesa|Casa|11/12/2025|COMPLETED";

    Task t = tm.parseTask(line);

    // Verifiche
    EXPECT_EQ(t.description, "Fare la spesa");
    EXPECT_EQ(t.category, "Casa");
    EXPECT_EQ(t.data, "11/12/2025");
    EXPECT_TRUE(t.completed); // Deve essere true
}
TEST(TaskManagerTest, ParseNotCompletedTask) {
    TaskManager tm;
    string line = "Fare la spesa|Casa|11/12/2025|NOT COMPLETED";

    Task t = tm.parseTask(line);

    // Verifiche
    EXPECT_EQ(t.description, "Fare la spesa");
    EXPECT_EQ(t.category, "Casa");
    EXPECT_EQ(t.data, "11/12/2025");
    EXPECT_TRUE(t.completed); // Deve essere false
}

TEST(TaskManagerTest, AddTaskTest ) {
    TaskManager tm;
    Task t("Fare la spesa", "Casa", "11/12/2025", false);
    // Chiamiamo la funzione che vogliamo testare
    tm.addTask(t);

    // Verifica: Controlliamo se la task è stata salvata
    vector<Task> storedTasks = tm.getTasks();

    // Controlliamo che la lista ora contenga 1 elemento
    ASSERT_EQ(storedTasks.size(), 1);

    // Controlliamo che l'elemento salvato sia identico a quello inserito
    EXPECT_EQ(storedTasks[0].description, "Fare la spesa");
    EXPECT_EQ(storedTasks[0].category, "Casa");
}

TEST(TaskManagerTest, RemoveTask) {
    TaskManager tm;
    Task t1("Task 1", "Tasks", "11/12/2025", false);
    Task t2("Task 2", "Tasks", "11/12/2025", false);
    Task t3("Task 3", "Tasks", "11/12/2025", false);
    tm.addTask(t1);
    tm.addTask(t2);
    tm.removeTask(1);

    vector<Task> tasks = tm.getTasks();
    ASSERT_EQ(tasks.size(), 1);

    EXPECT_EQ(tasks[0].description, "Task 1");
    EXPECT_EQ(tasks[1].description, "Task 3");              // La terza task deve slittare indietro di 1
}
TEST(TaskManagerTest, RemoveTask_IndexOutOfBound){
    TaskManager tm;
    tm.addTask(Task("Task 1", "Tasks", "11/12/2025", false));
    tm.removeTask(100);
    ASSERT_EQ(tm.getTasks().size(), 1);             // La lista deve essere rimasta intatta
}
TEST(TaskManagertest, RemoveTask_NegativeIndex) {
    TaskManager tm;
    tm.addTask(Task("Task 1", "Tasks", "11/12/2025", false));
    tm.removeTask(-1);
    ASSERT_EQ(tm.getTasks().size(), 1);                // La lista deve essere rimasta intatta
}

TEST(TaskManagertest, CompleteTask) {
    TaskManager tm;
    tm.addTask(Task("Task 1", "Tasks", "11/12/2025", false));
    tm.completeTask(0);
    EXPECT_TRUE(tm.getTasks()[0].completed);            // Il campo completed deve essere diventato TRUE
}
TEST(TaskManagertest, CompleteTask_IndexOutOfBound) {
    TaskManager tm;
    tm.addTask(Task("Task 1", "Tasks", "11/12/2025", false));
    tm.completeTask(100);
    EXPECT_FALSE(tm.getTasks()[0].completed);               // La task originale non deve essere cambiata
}
TEST(TaskManagertest, CompleteTask_NegativeIndex) {
    TaskManager tm;
    tm.addTask(Task("Task 1", "Tasks", "11/12/2025", false));
    tm.removeTask(-1);
    EXPECT_FALSE(tm.getTasks()[0].completed);               // La task originale non deve essere cambiata
}

TEST(TaskManagerTest, CountTaskNotCompleted) {
    TaskManager tm;
    ASSERT_EQ(tm.getCount(), 0);
    tm.addTask(Task("Task 1", "Tasks", "11/12/2025", false));
    tm.addTask(Task("Task 2", "Tasks", "11/12/2025", false));
    ASSERT_EQ(tm.getCount(), 2);                // Contatore task non completate = 2
    tm.completeTask(0);
    ASSERT_EQ(tm.getCount(), 1);                // Il contatore viene decrementato di 1
}