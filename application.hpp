#pragma once
#include <iostream>
#include <numeric>
#include <vector>
#include <string>

enum class state{
    MENU,
    ADD_TASK,
    VIEW_TASKS,
    EXIT
};

class Application{
private:
    ToDoList m_list;
    state m_state;

    void EnterDescription(std::string& description);
    void EnterChoiseMenu(int& choise);

    void StateAddTask();
    void StateViewTasks();
    int StateMenu();
    void UpdataState();
public:

    Application():m_state(state::MENU){}

    void SetState(const state& st){m_state = st;}

    void Run();
};