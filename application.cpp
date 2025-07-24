#include "task.hpp"
#include "todolist.hpp"
#include "application.hpp"


void Application::EnterDescription(std::string& description){
    std::cout<<"Enter description for to-do list: ";
    std::getline(std::cin, description);
    while(description == ""){
        std::cerr<<"Description do not be empty!"<<'\n';
        std::cin.clear();
        std::cout<<"Enter description for to-do list: ";
        std::getline(std::cin, description);
    }
}

void Application::EnterChoiseMenu(int& choise){
    std::cout<<"Enter your choise: ";
    std::cin>>choise;
    while(std::cin.fail() || choise < 0 || choise > 2){
        std::cerr<<"Chiose was be at 0 to 2 and not be letter!"<<'\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Enter your choise: ";
        std::cin>>choise;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Application::StateAddTask(){
    std::cout<<"_________________ADD NEW TASK______________"<<'\n';
    std::string description;
    EnterDescription(description);
    m_list.addTask(description);
    m_state = state::MENU;
}

void Application::StateViewTasks(){
    std::cout<<"______________VIEW TASKS______________"<<'\n';
    m_list.viewTasks();
    m_state = state::MENU;
}

int Application::StateMenu(){
    std::cout<<"______________MENU_______________"<<'\n'
             <<"What you whant to do? "<<'\n'
             <<"0 - Exit,"<<'\n'
             <<"1 - Add new task,"<<'\n'
             <<"2 - View all tasks."<<'\n';
    int choise = -1;
    EnterChoiseMenu(choise);
    return choise;
}

void Application::UpdataState(){
    int choise = StateMenu();
    switch (choise){
        case 0:
            SetState(state::EXIT);
            break;
        case 1:
            SetState(state::ADD_TASK);
            break;
        case 2:
            SetState(state::VIEW_TASKS);
            break;
    }
}

void Application::Run(){
    do{
        switch (m_state){
            case state::MENU:
                UpdataState();
                break;
            case state::ADD_TASK:
                StateAddTask();
                break;
            case state::VIEW_TASKS:
                StateViewTasks();
                break;
            case state::EXIT:
                break;
        }
        if(m_state == state::EXIT){
            break;
        }
    }
    while(true);
}