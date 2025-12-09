//
// Created by monet on 04/12/2025.
//

#ifndef LABPROGRAMMAZIONE_TASK_H
#define LABPROGRAMMAZIONE_TASK_H
#include <string>
using namespace std;

class Task {
public:
    string description;
    string category;
    string data;
    bool completed;

    Task(string des, string cat, string d, bool c) : description(des), category(cat), data(d), completed(c) {}
};


#endif //LABPROGRAMMAZIONE_TASK_H