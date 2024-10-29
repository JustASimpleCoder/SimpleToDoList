#include <iostream> 
#include <vector>  
#include <string>  



int main(int argc, char* argv[]) {
   
    std::cout << "Currently list fo tasks [" << 5  << "] " << std::endl;

    std::string currentTask = "";
    std::cout << "Would you like to Add (A), Delete (D) or Mark Complete (M), or list all tasks (L) " << std::endl;

    while(true){
        while(currentTask != "A" || currentTask != "D" || currentTask != "M" ){
            std::cin >> currentTask;
            if(currentTask != "A" || currentTask != "D" || currentTask != "M"){
                std::cout << "please enter a valid task (A, D, or M)";
            }
        }
    }
    
    return 0;
}


