//
// Created by monet on 04/12/2025.
//

#ifndef LABPROGRAMMAZIONE_TASKMANAGER_H
#define LABPROGRAMMAZIONE_TASKMANAGER_H
using namespace std;
#include "Task.h"
#include <vector>
#include <fstream>

class TaskManager {
private:
    vector<Task> tasks;
    int count = 0;

public:
    int getCount();
    vector<Task> getTasks();
    // Funzione che prende una riga del file e la trasforma in una task
    Task parseTask(const string& line);
    void addTask(const Task& t);
    void removeTask(int index);
    void completeTask(int index);
    void showTask();
    void filterByCategory(const string& category) const;
    void saveToFile(const string& fileName) const;
    void loadFromFile(const string& fileName);
};


#endif //LABPROGRAMMAZIONE_TASKMANAGER_H