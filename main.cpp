#include <iostream>
#include <vector>
#include "error_handling.h"
#include "book.h"
#include "library.h"
#include "file_manager.h"

int main(){
    std::fstream inOutFile("library.txt", std::ios::in | std::ios::out);
    std::vector<Book> libraryList;
    bool bookExist = false;
    Library myLibrary(libraryList, bookExist);
    checkIfOpen(inOutFile);
    myLibrary.loadToLibrary(inOutFile);
    int menuChoice = 0;

    while(menuChoice != 5){
        std::cout << std::endl << "Main Menu" << std::endl
        << "1. Add a new book" << std::endl
        << "2. Lend books" << std::endl
        << "3. Return books" << std::endl
        << "4. View available books" << std::endl
        << "5. Exit" << std::endl << std::endl;

        do{
            std::cout << "Choice: ";
            menuChoice = intChecker(); //In error_handling.cpp
    
            if(menuChoice < 1 || menuChoice > 5)
                std::cout << "Choose 1-5"<< std::endl;
                
        }while (menuChoice < 1 || menuChoice > 5);

        switch(menuChoice){
            case 1:
                myLibrary.addBook();
                break;
            case 2:
                myLibrary.lendABook();
                break;
            case 3:
                myLibrary.returnABook();
                break;
            case 4:
                myLibrary.displayBooks();
                break;
            case 5:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                break;
        }
    }
    myLibrary.saveToFile(inOutFile);
    inOutFile.close();
    return 0;
}