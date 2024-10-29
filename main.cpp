#include <iostream> 
#include <vector>  
#include <string>  

std::vector<std::string> taskList;

bool addTask(std::string task){
    if(task != ""){
        int taskNum = taskList.size() + 1;
        std::string taskToAdd = std::to_string(taskNum)  + ". " + task + " (In Progress)";
        taskList.push_back(taskToAdd);
        return true;
    }else{
        std::cout << "Could not add the new task as it had no value. Please enter a task with characters \n";
        return false;
    }
}
bool deleteTask(int taskNumber){
    if(taskNumber <= 0 || taskNumber > taskList.size()){
        std::cout << "Please enter a valid task number from 1 to the number of tasks (number of tasks: " << taskList.size() << " ) \n" << std::endl;
        return false;
    }else{
        taskList.erase(taskList.begin() + taskNumber - 1);
        return true;
    }
}

void markCompleteTask(int taskNumber){
    if(taskNumber <= 0 || taskNumber > taskList.size()){
        std::cout << "Please enter a valid task number from 1 to the number of tasks (number of tasks: " << taskList.size() << " ) \n" << std::endl;
    }

    std::string task = taskList[taskNumber - 1];
    int foundIndex = task.find("(In Progress)");
    if(foundIndex != std::string::npos & foundIndex > 0){
        std::string completedTask = "";
        completedTask = task.substr(0, foundIndex);
        completedTask += "(Completed)";
    }else{
        std::cout << "Task number " << taskNumber << ". is already marked complete";
    }
}


void listAllTask(){
    std::cout << "Task List:  " << "\n";
    for(auto &tasks: taskList){
        std::cout << tasks << "\n";
    }
    std::cout << "\n";
    std::cout << "End of list " << "\n";
}

int main(int argc, char* argv[]) {
   
    std::cout << "Currently list fo tasks [" << 5  << "] " << std::endl;
    std::string currentTask = "";
    std::cout << "Would you like to Add (A), Delete (D) or Mark Complete (M), or list all tasks (L) " << std::endl;
    std::cin >> currentTask;
    
    while(currentTask != "A" && currentTask != "D" && currentTask != "M" ){
        std::cout << "Please enter a valid task (A, D, M, L)";
        std::cin >> currentTask;
    }

    std::cout << " You have entered the task [" << currentTask  << "] \n" << std::endl;

    if(currentTask == "A"){
        std::string newTask = "";
        do{
            std::cout << "Please enter a new task to add: ";
            std::getline(std::cin, newTask);
        }while(!addTask(newTask));
    }


    listAllTask();

    return 0;
}


