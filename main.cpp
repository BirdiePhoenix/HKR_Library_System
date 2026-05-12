#include <iostream>
#include <vector>
#include "error_handling.h"
#include "book.h"
#include "library.h"

int main(){
    std::fstream inOutFile("library.txt", std::ios::in | std::ios::out);
    checkIfOpen(inOutFile); //In error_handling.cpp, checks if the file got open

    std::vector<Book> libraryList;
    bool bookExist = false; // Used when checking if a book exists in library
    Library myLibrary(libraryList, bookExist);
    myLibrary.loadToLibrary(inOutFile);

    int menuChoice = 0;

    while(menuChoice != 5){
        std::cout << "Main Menu" << std::endl
        << "1. Add a new book" << std::endl
        << "2. Lend books" << std::endl
        << "3. Return books" << std::endl
        << "4. View available books" << std::endl
        << "5. Exit" << std::endl << std::endl;

        mainMenuChoice(&menuChoice); //In error_handling.cpp, for validating the right input

        std::cout << "***********" << std::endl << std::endl;

        switch(menuChoice){
            case 1:
                myLibrary.addBook();
                break;
            case 2:
                myLibrary.lendBooks();
                break;
            case 3:
                myLibrary.returnBooks();
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

        std::cout << std::endl << std::endl << "***********"  << std::endl;
    }
    myLibrary.saveToFile(inOutFile);
    inOutFile.close();
    return 0;
}