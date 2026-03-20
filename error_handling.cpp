#include "error_handling.h"

int intChecker(){ //Checks if an input is an integer
    int number;
    while(!(std::cin >> number)){
            std::cerr << "Invalid input. Input an integer." << std::endl;
            std::cin.clear();
            clearBuffer();
        } 
    return number;
}


void clearBuffer(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}