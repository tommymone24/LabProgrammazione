//
// Created by monet on 04/12/2025.
//

#include "TaskManager.h"

#include <iostream>
#include <ostream>
#include <sstream>

// Funzione interna: prende una riga del file e la trasforma in una task
Task TaskManager::parseTask(const string& line) {
    stringstream ss(line);                                  // Crea un oggetto stringstream che permette di leggere la stringa come se fosse un file.
    string description, category, date, completedStr;

    getline(ss, description, '|');                  // Legge i campi di ss fino a | e salva in description e cosi' via
    getline(ss, category, '|');
    getline(ss, date, '|');
    getline(ss, completedStr, '|');

    bool completed = (completedStr == "COMPLETED");

    return Task(description, category, date, completed);
}


void TaskManager::addTask(const Task& t) {
    tasks.push_back(t);
}

void TaskManager::removeTask(int index) {
    if (index < 0 || index >= tasks.size()) {
        cout << "Invalid index" << endl;
        return;
    }
    tasks.erase(tasks.begin() + index);
}

void TaskManager::completeTask(int index) {
    if (index < 0 || index >= tasks.size()) {
        cout << "Invalid index" << endl;
        return;
    }
    tasks[index].completed = true;
    cout << "Task completed!" << endl;
}

void TaskManager::showTask() const {
    if (tasks.empty()) {
        std::cout << "No Tasks";
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << tasks[i].description << "|"
        << tasks[i].category << "|"
        << tasks[i].data << "|"
        << (tasks[i].completed ? "[COMPLETED]" : "[NOT COMPLETED]") << endl;
    }
}

void TaskManager::filterByCategory(const string& category) const {
    bool found = false;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].category == category) {
            found = true;
            cout << tasks[i].description << "|"
            << tasks[i].category << "|"
            << tasks[i].data << "|"
            << (tasks[i].completed ? "[COMPLETED]" : "[NOT COMPLETED]");
        }
    }
    if (!found) {
        cout << "Task not found in category: " << category << endl;
    }
}

void TaskManager::saveToFile(const string& fileName) const{
    ofstream file(fileName);

    for (const auto& t : tasks) {
        file << t.description << "|"
             << t.category << "|"
             << t.data << "|"
             << (t.completed ? "1" : "0") << endl;
    }
}

void TaskManager::loadFromFile(const string& fileName) {
    tasks.clear();

    ifstream file(fileName);
    string line;

    while(getline(file, line)) {
        if (!line.empty()) {
            tasks.push_back(parseTask(line));
        }
    }
}
