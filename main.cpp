using namespace std;
#include <iostream>
#include "src/Task.h"
#include "src/TaskManager.h"


int main() {
    TaskManager taskManager;
    int scelta;

    // Tentativo di caricare un file all'avvio
    taskManager.loadFromFile("tasks.txt");

    do {
        cout << "===== TO DO LIST =====\n";
        cout << "1. AGGIUNGI TASKS\n";
        cout << "2. RIMUOVI TASKS\n";
        cout << "3. COMPLETA TASKS\n";
        cout << "4. VISUALIZZA TASKS\n";
        cout << "5. FILTRA PER CATEGORIA\n";
        cout << "6. SALVA SU FILE\n";
        cout << "0. ESCI\n";
        cin >> scelta;
        cin.ignore();                       // pulisce il buffer

        if (scelta == 1) {
            std::string titolo, categoria, data;

            std::cout << "Descrizione: ";
            std::getline(std::cin, titolo);
            std::cout << "Categoria: ";
            std::getline(std::cin, categoria);
            std::cout << "Data (GG-MM-AAAA): ";
            std::getline(std::cin, data);

            taskManager.addTask(Task(titolo, categoria, data, false));
            std::cout << "Task aggiunta!\n";
        }else if (scelta == 2) {
            int index;
            cout << "Numero della task da rimuovere: ";
            cin >> index;
            taskManager.removeTask(index);
        }else if (scelta == 3) {
            int index;
            cout << "Numero della task da completare: ";
            cin >> index;
            taskManager.completeTask(index);
        }else if (scelta == 4) {
            taskManager.showTask();
            cout << endl;
        }else if (scelta == 5) {
            string cat;
            cout << "Categoria da cui filtrare: " ;
            getline(cin, cat);
            vector<Task> risultati = taskManager.filterByCategory(cat);
            if (risultati.empty()) {
                cout << "Nessuna task trovata per la categoria '" << cat << "'." << endl;
            } else {
                // Se ci sono task, le stampo (usando lo stesso formato di showTask)
                for (const auto& task : risultati) {
                    cout << task.description << " | "
                         << task.category << " | "
                         << task.data << " | "
                         << (task.completed ? "[COMPLETED]" : "[NOT COMPLETED]") << endl;
                }
            }
        }else if (scelta == 6) {
            taskManager.saveToFile("tasks.txt");
            cout << "Salvato!\n";
        }
    }while (scelta != 0);

    // Salvataggio automatico alla chiusura
    taskManager.saveToFile("tasks.txt");

    return 0;
}