#include <iostream> 
#include <vector>  
#include <string>  

std::vector<std::string> taskList = {};
bool addTask(std::string task){
    if(task != ""){
        int taskNum = taskList.size() + 1;
        std::string taskToAdd = std::to_string(taskNum)  + ". " + task + " (In Progress)";
        taskList.push_back(taskToAdd);
        std::cout << "Successfully added new task [" << task << "] to the list \n";
        return true;
    }else{
        std::cout << "Could not add the new task as it had no value. Please enter a task with characters \n";
        return false;
    }
}

bool deleteTask(int taskNumber){
    if(taskNumber <= 0 || taskNumber > taskList.size()){
        std::cout << "Please enter a valid task number from 1 to the number of tasks ( " << taskList.size() << ")" << std::endl;
        return false;
    }else{
        taskList.erase(taskList.begin() + taskNumber - 1);
        std::cout << "Deleted task [" << taskList.size() << "] from the list" << std::endl;
        return true;
    }
}

bool markCompleteTask(int taskNumber){
    if(taskNumber <= 0 || taskNumber > taskList.size()){
        std::cout << "Please enter a valid task number from 1 to the number of tasks (number of tasks: " << taskList.size() << " ) \n" << std::endl;
        return false;
    }

    std::string task = taskList[taskNumber - 1];
    int foundIndex = task.find("(In Progress)");
    if(foundIndex != std::string::npos & foundIndex > 0){
        std::string completedTask = "";
        completedTask = task.substr(0, foundIndex);
        std::cout << "marked task as completed [" << completedTask << "] \n" << std::endl;
        completedTask += "(Completed)";
        taskList[taskNumber - 1] = completedTask;
        return true;
    }else{
        std::cout << "Task number " << taskNumber << ". is already marked complete";
        return false;
    }
}

void listAllTask(){
    std::cout << "Task List:  " << "\n";
    for(auto &tasks: taskList){
        std::cout << tasks << "\n";
    }
    std::cout << "End of list " << "\n";
}

int main(int argc, char* argv[]) {
    while(true){
        std::string currentTask = "";
        std::cout << "Would you like to Add (A), Delete (D), Mark Complete (M), list all tasks (L) or Quit Program (Q)" << std::endl;
        std::cin >> currentTask;
        
        while(currentTask != "A" && currentTask != "D" && currentTask != "M"  && currentTask != "L"  && currentTask != "Q" ){
            std::cout << "Please enter a valid task (A, D, M, L or Q)";
            std::cin >> currentTask;
        }
        std::cout << "You have entered the task [" << currentTask  << "] \n" << std::endl;

        if(currentTask == "Q"){
            std::cout << "Quitting Program \n" << std::endl;
            return 0;
        }

        if(currentTask == "A"){
            std::string newTask = "";
            do{
                std::cout << "Please enter a new task to add: ";
                std::getline(std::cin, newTask);
            }while(!addTask(newTask));
        }
        if(currentTask == "D"){
            int taskNum = 0;
            do{
                listAllTask();
                std::cout << "Please enter the task number to delete from the list above";
                std::cin >> taskNum;
                if (std::cin.fail()) {
                    std::cin.clear();
                    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter an integer.\n";
                    taskNum = -1;
                }
                
            }while(!deleteTask(taskNum));
            
        }

        if(currentTask == "M"){
            int taskNum = 0;
            do{
                listAllTask();
                std::cout << "Please enter the task number to mark as complete: ";
                std::cin >> taskNum;
                if (std::cin.fail()) {
                    std::cin.clear();
                    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter an integer.\n";
                    taskNum = -1;
                }
                
            }while(!markCompleteTask(taskNum));
        }

        if(currentTask == "L"){
            listAllTask();
        }
    }
    return 0;
}


