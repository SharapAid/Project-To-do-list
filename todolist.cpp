#include "task.hpp"
#include "todolist.hpp"
#include "application.hpp"

void ToDoList::addTask(const std::string& description){
    Task new_task(description);
    m_tasks.push_back(new_task);
}

void ToDoList::viewTasks() const{
    if(m_tasks.empty()){
        std::cout<<"You have not the task in this moment!"<<'\n';
    }
    for (size_t i = 0; i < m_tasks.size(); ++i) {
        const Task& task = m_tasks[i];

        std::cout << i + 1 << ". ";

        if(!task.GetMark()){
            std::cout << "[X] ";
        }
        else{
            std::cout << "[ ] ";
        }

        std::cout << task.GetDescription() << '\n';
    }
}