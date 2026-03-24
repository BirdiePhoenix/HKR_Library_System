#include "library.h"
#include "error_handling.h"
#include <iomanip>

Library::Library(std::vector<Book> library, bool bookExist){
    mLibrary = new std::vector<Book>;
    *mLibrary = library;
    mBookExist = bookExist;
}

Library::~Library(){
    delete mLibrary;
    std::cout << "Library was deleted";
}

void Library::addBook(){
    std::string title;
    std::string author;
    setBookExist(false);
    
    clearBuffer();
    
    std::cout << "What is the title of the book you want to add? ";
    std::getline(std::cin, title);
    std::cout << title << std::endl;

    std::cout << "Who is the author of the book you want to add? ";
    std::getline(std::cin, author);
    std::cout << title << author << std::endl;

    for(int i = 0; i < mLibrary->size(); i++){
        if((*mLibrary)[i].getTitle() == title && (*mLibrary)[i].getAuthor() == author){
            std::cout << "That book does already exist" << std::endl;
            setBookExist(true);
            break;
        }
    }

    if(!getBookExist()){
        Book newBook(title, author, true); 
        mLibrary->push_back(newBook);
    }
}

void Library::lendABook(){
    clearBuffer();

    int amountOfBooks = insertAmountOfBooks(); 
    Book* pBook; 

    if(amountOfBooks > 1){ //Several books
        std::vector<std::string>* titlesList = new std::vector<std::string>;
        severalBooks(titlesList);
        for(int i = 0; i < titlesList->size(); i++){
            std::cout << (*titlesList)[i] << std::endl;
        }
        for(int i = 0; i < titlesList->size(); i++){
            for(int j = 0; j < mLibrary->size(); j++){
                pBook = &(*mLibrary)[j];
                if((*titlesList)[i] == pBook->getTitle()){
                    (*mLibrary)[j].borrowBook();
                    break;
                }
                else if(j == mLibrary->size() - 1){
                    std::cout << (*titlesList)[i] << " does not exist" << std::endl;
                }
            }
        }
        delete titlesList;
    }
    else{ //One book
        clearBuffer();
        std::string whatTitle;
        setBookExist(false);
        do{
            std::cout << "Insert book title or write 'Exit' to go back to menu ";
            std::getline(std::cin, whatTitle);

            if(whatTitle == "Exit"){
                break;
            }
            
            checkIfBookExist(&whatTitle);
        }while(!getBookExist());

        for(int i = 0; i <= mLibrary->size() - 1; i++){
            pBook = &(*mLibrary)[i];
            if(whatTitle == pBook->getTitle()){
                pBook->borrowBook();
            }
        }
    }
}

void Library::returnABook(){
    clearBuffer();
        
    int amountOfBooks = insertAmountOfBooks();   
    Book* pBook;  

    if(amountOfBooks > 1){ //Several Books
        std::vector<std::string>* titlesList = new std::vector<std::string>;
        severalBooks(titlesList);
        for(int i = 0; i < titlesList->size(); i++){
            for(int j = 0; j < mLibrary->size(); j++){
                pBook = &(*mLibrary)[j];
                if((*titlesList)[i] == pBook->getTitle()){
                    pBook->returnBook();
                    break;
                }
                else if(j == (*mLibrary).size() - 1){
                    std::cout << (*titlesList)[i] << " does not exist" << std::endl;
                }
            }
        }
        delete titlesList;
    }
    else{ //One Book
        clearBuffer();
        std::string whatTitle;
        setBookExist(false);
        do{
            std::cout << "Insert book title or write 'Exit' to go back to menu ";
            std::getline(std::cin, whatTitle);

            if(whatTitle == "Exit"){
                break;
            }

            checkIfBookExist(&whatTitle);
        }while(!getBookExist());

        for(int i = 0; i <= mLibrary->size() - 1; i++){
            pBook = &(*mLibrary)[i];
            if(whatTitle == pBook->getTitle()){
                pBook->returnBook();
            }
        }
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
    }
}

void Library::displayBooks(){
    std::cout << std::left << std::setw(20) << "TITLE" << std::right << std::setw(20) << "AUTHOR" << std::setw(20) <<  "AVAILABLE" << std::endl;
        for(int i = 0; i < mLibrary->size(); i++){
            Book *pBook;
            pBook = &(*mLibrary)[i];
            pBook->displayDetails();
        }
}

void Library::checkIfBookExist(std::string* whatTitle){
    Book* pBook;
    for(int i = 0; i < mLibrary->size(); i++){
        pBook = &(*mLibrary)[i];
        if(pBook->getTitle() == *whatTitle){
            setBookExist(true);
            break;
        }
        }
        if(!getBookExist()){
            std::cout << "The book does not exist" << std::endl;
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
            mLibrary->push_back(newBook);
        }

        lineCount++;
    }

    inOutFile.clear();
    inOutFile.seekg(0);
}

void Library::saveToFile(std::fstream &inOutFile){
    Book* pBook;

    for(int i = 0; i < mLibrary->size(); i++){
        pBook = &(*mLibrary)[i];
        inOutFile << pBook->getTitle() << std::endl;
        inOutFile << pBook->getAuthor() << std::endl;

        if((*mLibrary)[i].getAvailable()){
            inOutFile << "Yes";
        }
        else{
            inOutFile << "No";
        }

        if(i < mLibrary->size()-1){
            inOutFile << std::endl;
        }
    }
}

bool Library::getBookExist(){
    return mBookExist;
}

void Library::setBookExist(bool bookExist){
    mBookExist = bookExist;
}