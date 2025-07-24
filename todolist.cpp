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

void ToDoList::markTask(int taskNumber, bool complete){
    if(taskNumber - 1 > m_tasks.size()){
        std::cout<<"Task whis dis number absent!"<<'\n';
    }
    else{
        if(complete){
            m_tasks[taskNumber - 1].markCompleted();
            std::cout<<"Task whis number "<<taskNumber<<" is complete!"<<'\n';
        }
        else{
            m_tasks[taskNumber].markIncompleted();
            std::cout<<"Task whis number "<<taskNumber<<" is incomplete!"<<'\n';
        } 
    }
   
}

void ToDoList::deleteTask(int taskNumber){
    if(taskNumber > m_tasks.size()){
        std::cout<<"Task whis dis number absent!"<<'\n';
    }
    else{
        m_tasks.erase(m_tasks.begin() + (taskNumber-1));
        std::cout<<"Task whis number "<<taskNumber<<" is delete!"<<'\n';
    }
   
}

void ToDoList::saveTasksToFile(const std::string& filename) const{
    std::ofstream save;
    try{
        save.open(filename);
        if(save.is_open()){
            for(const auto& task : m_tasks){
                save<<task;
                std::cout<<"Task "<<task.GetDescription()<<" is save!"<<'\n';
            }
            save.close();
        }
        else{
            std::cerr<<"Error, file not open!"<<'\n';
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}

void ToDoList::loadTasksFromFile(const std::string& filename){
    std::ifstream load;
    load.open(filename);
    if(load.is_open()){
        m_tasks.clear();
        Task temp_task;
        while(load>>temp_task){
            m_tasks.push_back(temp_task);  
        }
        std::cout<<"All task is load!"<<'\n';
    }
    else{
        std::cerr<<"Error, file not open!"<<'\n';
    }
}