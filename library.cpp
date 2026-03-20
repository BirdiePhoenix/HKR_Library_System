#include "library.h"
#include "error_handling.h"

Library::Library(std::vector <Book> library){
    mLibrary = library;
}

void Library::addBook(){
    std::string title;
    std::string author;
    
    clearBuffer();
    
    std::cout << "What is the title of the book you want to add? ";
    std::getline(std::cin, title);
    std::cout << title << std::endl;

    std::cout << "Who is the author of the book you want to add? ";
    std::getline(std::cin, author);
    std::cout << title << author << std::endl;

    Book newBook(title, author, true);
    
    mLibrary.push_back(newBook);
}

void Library::lendABook(){
    clearBuffer();
        
    std::string whatTitle;
    std::cout << "What is the book title? ";
    std::getline(std::cin, whatTitle);

    for(int i = 0; i <= mLibrary.size() - 1; i++){
        if(whatTitle == mLibrary[i].getTitle()){
            mLibrary[i].borrowBook();
        }
    }
}

void Library::returnABook(){
    clearBuffer();
        
    std::string whatTitle;
    std::cout << "What book do you want to return? ";
    std::getline(std::cin, whatTitle);

    for(int i = 0; i <= mLibrary.size() - 1; i++){
        if(whatTitle == mLibrary[i].getTitle()){
            mLibrary[i].returnBook();
        }
    }
}

void Library::displayBooks(){
    std::cout << "Title     " << "Author     " << "Available" << std::endl;
        
        for(int i = 0; i < mLibrary.size(); i++){
            mLibrary[i].displayDetails();
        }
}

void Library::severalBooks(){

}