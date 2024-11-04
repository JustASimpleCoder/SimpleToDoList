#include <iostream> 
#include <vector>  
#include <string>  

#include <fstream>

std::vector<std::string> taskList = {};

void writeTaskList(){
    std::ofstream file("TaskList.txt"); // Open the file in write mode
    if (file.is_open()) {
        for(auto &task:taskList){
            file << task + "\n";
        }
        file.close(); // Close the file after writing
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }

}

void readAndGenerateTaskList(){
    std::ifstream file("TaskList.txt"); // Open the file in read mode
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) { 
            taskList.push_back(line); 
        }
        file.close(); 
    } else {
        std::cerr << "Unable to open file for reading.\n";
    }
}

bool addTask(std::string task){
    if(task != ""){
        std::string taskToAdd = task + " (In Progress)";
        taskList.push_back(taskToAdd);
        std::cout << "Successfully added new task [" << task << "] to the list \n";
        return true;
    }else{
        std::cout << "Could not add the new task as it was an empty string. Please enter a task with characters \n";
        return false;
    }
}

bool deleteTask(int taskNumber){
    if(taskNumber <= 0 || taskNumber > taskList.size()){
        std::cout << "Please enter a valid task number from 1 to " << taskList.size() << " \n" << std::endl;
        return false;
    }else{
        taskList.erase(taskList.begin() + taskNumber - 1);
        std::cout << "Deleted task [" << taskList.size() << "] from the list \n" << std::endl;
        return true;
    }
    //TODO create a re-shuffle of tasks,
}

bool markCompleteTask(int taskNumber){
    if(taskNumber <= 0 || taskNumber > taskList.size()){
        std::cout << "Please enter a valid task number from 1 to " << taskList.size() << "\n" << std::endl;
        return false;
    }

    std::string task = taskList[taskNumber - 1];
    int foundIndex = task.find("(In Progress)");
    if(foundIndex != std::string::npos & foundIndex > 0){
        std::string completedTask = "";
        completedTask = task.substr(0, foundIndex);
        std::cout << "Marked task as completed [" << completedTask << "] \n" << std::endl;
        completedTask += "(Completed)";
        taskList[taskNumber - 1] = completedTask;
        return true;
    }else{
        std::cout << "Task number " << taskNumber << ". is already marked complete \n";
        return false;
    }
}

void listAllTask(){
    std::cout << "______Task List______" << "\n";
    for(int i = 0; i < taskList.size(); i++){
        std::cout << i << ". " << taskList[i] << "\n";
    }
    std::cout << "______End of list______" << "\n";
}


bool mainLoopLogic(){
    std::string currentTask = "";
    std::cout << "Would you like to Add (A), Delete (D), Mark Complete (M), list all tasks (L) or Quit Program (Q)" << std::endl;
    while(currentTask != "A" && currentTask != "D" && currentTask != "M"  && currentTask != "L"  && currentTask != "Q" ){
        std::cout << "Please enter a valid task (A, D, M, L or Q)";
        std::cin >> currentTask;
    }

    std::cout << "You have entered the task [" << currentTask  << "] \n" << std::endl;
    if(currentTask == "Q"){
        std::cout << "Quitting Program \n" << std::endl;
        return false;
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
                std::cout << "Invalid input. Please enter an integer. \n";
                taskNum = -1;
            }

        }while(!markCompleteTask(taskNum));
    }

    if(currentTask == "L"){
        listAllTask();
    }

    return true;
}

int main(int argc, char* argv[]) {
    readAndGenerateTaskList();
    bool run = true;
    
    while(run){
        run = mainLoopLogic();
    }

    writeTaskList();
    return 0;
}


