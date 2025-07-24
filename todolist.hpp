#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

class ToDoList{
private:
    std::vector<Task> m_tasks;
public:

    int GetSizeList()const {return m_tasks.size();}

    void addTask(const std::string& description);
    void viewTasks() const;
    void markTask(int taskNumber, bool complete);
    void deleteTask(int taskNumber);
    void saveTasksToFile(const std::string& filename) const;
    void loadTasksFromFile(const std::string& filename);
};