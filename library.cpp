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

    int amountOfBooks;

    do{
        std::cout << "How many books do you want to lend out? ";
        amountOfBooks = intChecker();

        if(amountOfBooks < 1)
            std::cout << "Amount of books can't be less than 1." << std::endl;

    }while(amountOfBooks < 1);

    if(amountOfBooks > 1){
        std::vector <std::string> titlesList;
        severalBooks(&titlesList);
        for(int i = 0; i < titlesList.size(); i++){
            std::cout << titlesList[i] << std::endl;
        }
        for(int i = 0; i < titlesList.size(); i++){
            for(int j = 0; j < mLibrary.size(); j++){
                if(titlesList[i] == mLibrary[j].getTitle()){
                    mLibrary[j].borrowBook();
                }
            }
        }
    }
    else{
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
}

void Library::returnABook(){
    clearBuffer();
        
    int amountOfBooks;

    do{
        std::cout << "How many books do you want to return? ";
        amountOfBooks = intChecker();

        if(amountOfBooks < 1)
            std::cout << "Amount of books can't be less than 1." << std::endl;

    }while(amountOfBooks < 1);

    if(amountOfBooks > 1){
        std::vector <std::string> titlesList;
        severalBooks(&titlesList);
        for(int i = 0; i < titlesList.size(); i++){
            for(int j = 0; j < mLibrary.size(); j++){
                if(titlesList[i] == mLibrary[j].getTitle()){
                    mLibrary[j].returnBook();
                }
            }
        }
    }
    else{
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
}

void Library::displayBooks(){
    std::cout << "Title     " << "Author     " << "Available" << std::endl;
        
        for(int i = 0; i < mLibrary.size(); i++){
            mLibrary[i].displayDetails();
        }
}

void Library::severalBooks(std::vector <std::string> *titlesList){
    clearBuffer();
    std::string severalTitles;
    std::cout << "Insert the book titles, seperate them with a ';' " << std::endl;
    std::getline(std::cin, severalTitles);
    severalTitles.append(";");
    
    int listIndex = 0;
    int wordStart = 0;

    for(int i = 0; i < severalTitles.length(); i++){
        if(severalTitles[i] == ';' || i == severalTitles.length() - 1){
            std::string sub = severalTitles.substr(wordStart, i-wordStart);
            titlesList->push_back(sub);
            wordStart = i+1;
        }
        std::cout << "i = " << i << std::endl
        << "wordStart = " << wordStart << std::endl;
    }
}

void Library::loadToLibrary(std::fstream &inOutFile){
    std::string line;
    std::string title;
    std::string author;
    bool isAvailable;
    int lineCount = 1;
    std::cout << "Hello" << std::endl;

    while(std::getline(inOutFile, line)){  
        std::cout << line << std::endl;
        if((lineCount+2)%3 == 0){
            title = line;
        }
        else if((lineCount+1)%3 == 0){
            author = line;
        }
        else if(lineCount%3 == 0){
            if(line == "Yes"){
                isAvailable = true;
            }
            else if(line == "No"){
                isAvailable = false;
            }

            Book newBook(title, author, isAvailable);
            mLibrary.push_back(newBook);
        }

        lineCount++;
    }

    inOutFile.clear();
    inOutFile.seekg(0);
}

void Library::saveToFile(std::fstream &inOutFile){

    for(int i = 0; i < mLibrary.size(); i++){
        inOutFile << mLibrary[i].getTitle() << std::endl;
        inOutFile << mLibrary[i].getAuthor() << std::endl;

        if(mLibrary[i].getAvailable()){
            inOutFile << "Yes" << std::endl;
        }
        else{
            inOutFile << "No" << std::endl;
        }
    }
}