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