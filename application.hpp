#pragma once
#include <iostream>
#include <numeric>
#include <vector>
#include <string>

enum class state{
    MENU,
    ADD_TASK,
    MARK_TASK,
    DELETE_TASK,
    VIEW_TASKS,
    EXIT
};

class Application{
private:
    ToDoList m_list;
    state m_state;

    void EnterDescription(std::string& description);
    void EnterChoiseMenu(int& choise);
    void EnterNumberTask(int& numTask);
    void EnterCompleteBool(bool& complete);

    void StateAddTask();
    void StateViewTasks();
    void StateMarkTask();
    void StateDeleteTask();
    int StateMenu();
    void UpdataState();
public:

    Application():m_state(state::MENU){
        m_list.loadTasksFromFile("task.txt");
    }

    ~Application(){
        m_list.saveTasksToFile("task.txt");
    }

    void SetState(const state& st){m_state = st;}

    void Run();
};