#pragma once
#include <iostream>
#include <string>

class Task{
private:
    std::string m_description;
    bool m_is_complited;
public:
    Task(const std::string& description);

    void markCompleted();
    void markIncompleted();

    std::string GetDescription() const{return m_description;}
    bool GetMark() const{return m_is_complited;}
};
