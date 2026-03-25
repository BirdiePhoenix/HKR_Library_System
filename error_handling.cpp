#include "error_handling.h"

int intChecker(){ //Checks if an input is an integer
    int number;
    while(!(std::cin >> number)){ //If user doesn't insert int
            std::cerr << "Invalid input. Input an integer." << std::endl;
            std::cin.clear();
            ignoreBuffer();
        } 
    return number;
}

void ignoreBuffer(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int insertAmountOfBooks(){ //Checks if input is int and if it is more than 0
    int amountOfBooks;
    do{
        std::cout << "How many books do you want to insert? Insert '0' to go back to main menu. " ;
        amountOfBooks = intChecker();
        if(amountOfBooks == 0){
            break;
        }
        else if(amountOfBooks < 1)
            std::cout << "Amount of books can't be less than 1." << std::endl;

    }while(amountOfBooks < 1);

    return amountOfBooks;
}

void checkIfOpen(std::fstream &inOutFile){ //Checks so the library.txt opens properly

    if(!inOutFile)
        std::cerr << "Failed to open library.txt for reading" << std::endl;

    if(inOutFile.is_open()){
        std::cout << "is_open() flag got triggered" << std::endl;
    }
    else{
        std::cerr << "Error opening file" << std::endl;
    }
}

void mainMenuChoice(int* menuChoice){
    do{
        std::cout << "Choice: ";
        *menuChoice = intChecker(); //In error_handling.cpp, checks so user inputs int

        if(*menuChoice < 1 || *menuChoice > 5)
            std::cout << "Choose 1-5"<< std::endl;
            
    }while (*menuChoice < 1 || *menuChoice > 5);
}