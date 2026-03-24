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

int insertAmountOfBooks(){
    int amountOfBooks;
    do{
        std::cout << "How many books do you want to insert? ";
        amountOfBooks = intChecker();

        if(amountOfBooks < 1)
            std::cout << "Amount of books can't be less than 1." << std::endl;

    }while(amountOfBooks < 1);

    return amountOfBooks;
}