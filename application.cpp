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
    while(std::cin.fail() || choise < 0 || choise > 4){
        std::cerr<<"Chiose was be between 0 to 4 and not be letter!"<<'\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Enter your choise: ";
        std::cin>>choise;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Application::EnterNumberTask(int& numTask){
    size_t list_size = m_list.GetSizeList();
    std::cout<<"Enter number of task: ";
    std::cin>>numTask;
    while(std::cin.fail() || numTask < 1 || numTask > list_size){
        std::cerr<<"Number was be between 1 to"<<list_size<< " and not be letter!"<<'\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Enter number of task: ";
        std::cin>>numTask;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Application::EnterCompleteBool(bool& complete){
    std::cout<<"Enter false - 0 or true - 1: ";
    std::cin>>complete;
    while(std::cin.fail() || complete < 0 || complete > 1){
        std::cerr<<"Bool was be between 0 to 1 and not be letter!"<<'\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Enter false - 0 or true - 1: ";
        std::cin>>complete;
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

void Application::StateMarkTask(){
    std::cout<<"______________MARK TASK_______________"<<'\n';
    int number_task = 0;
    bool is_complete;
    EnterNumberTask(number_task);
    EnterCompleteBool(is_complete);
    m_list.markTask(number_task, is_complete);
    m_state = state::MENU;
}

 void Application::StateDeleteTask(){
    std::cout<<"_______________________DELETE TASK_____________________"<<'\n';
    int number_task = 0;
    EnterNumberTask(number_task);
    m_list.deleteTask(number_task);
    m_state = state::MENU;
 }

int Application::StateMenu(){
    std::cout<<"______________MENU_______________"<<'\n'
             <<"What you whant to do? "<<'\n'
             <<"0 - Exit,"<<'\n'
             <<"1 - Add new task,"<<'\n'
             <<"2 - View all tasks."<<'\n'
             <<"3 - Mark task."<<'\n'
             <<"4 - Delete task."<<'\n';
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
        case 3:
            SetState(state::MARK_TASK);
            break;
        case 4:
            SetState(state::DELETE_TASK);
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
            case state::MARK_TASK:
                StateMarkTask();
                break;
            case state::DELETE_TASK:
                StateDeleteTask();
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