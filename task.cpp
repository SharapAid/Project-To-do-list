#include "task.hpp"
#include "todolist.hpp"
#include "application.hpp"


Task::Task(const std::string& description)
    :m_description(description),
     m_is_complited(false)
{

}

void Task::markCompleted(){
    m_is_complited = true;
}

void Task::markIncompleted(){
    m_is_complited = false;
}

std::ostream& operator<<(std::ostream& os,const Task& task){
    os<<task.GetDescription()<<'\n';
    os<<task.GetMark()<<'\n';
    return os;
}

std::istream& operator>>(std::istream& is,Task& task){
    std::string description;
    bool complete_status;
    if(std::getline(is, description)){
        if(is>>complete_status){
            task.SetDescription(description);
            task.SetBoolComplete(complete_status);
            
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return is;
}