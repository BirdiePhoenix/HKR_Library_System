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

void insertAmountOfBooks(int* amountOfBooksPtr){ //Checks if input is int and if it is more than 0
    do{
        std::cout << "How many books do you want to insert? Insert '0' to go back to main menu. " ;
        *amountOfBooksPtr = intChecker();
        if(*amountOfBooksPtr == 0){
            break;
        }
        else if(*amountOfBooksPtr < 1)
            std::cout << "Amount of books can't be less than 1." << std::endl;

    }while(*amountOfBooksPtr < 1);
}

void mainMenuChoice(int* menuChoicePtr){ //Checks if input is int and if it is between 1-5
    do{
        std::cout << "Choice: ";
        *menuChoicePtr = intChecker(); //In error_handling.cpp, checks so user inputs int

        if(*menuChoicePtr < 1 || *menuChoicePtr > 5)
            std::cout << "Choose 1-5"<< std::endl;
            
    }while (*menuChoicePtr < 1 || *menuChoicePtr > 5);
}

void ignoreBuffer(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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