#pragma once
#include <iostream>
#include <string>

class Task{
private:
    std::string m_description;
    bool m_is_complited;
public:
    Task():m_description(""), m_is_complited(false){}
    Task(const std::string& description);

    friend std::ostream& operator<<(std::ostream& os,const Task& task);
    friend std::istream& operator>>(std::istream& is,Task& task);

    void markCompleted();
    void markIncompleted();

    void SetDescription(const std::string& description){m_description = description;}
    void SetBoolComplete(const bool& complete){m_is_complited = complete;}

    std::string GetDescription() const{return m_description;}
    bool GetMark() const{return m_is_complited;}
};
