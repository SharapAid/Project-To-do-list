#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class ToDoList{
private: 
    std::vector<Task> m_tasks;
public:

    void addTask(const std::string& description);
    void viewTasks() const;
};