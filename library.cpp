#include "library.h"
#include "error_handling.h"
#include <iomanip>

Library::Library(std::vector<Book> library, bool bookExist){ //Constructor
    mLibrary = new std::vector<Book>;
    *mLibrary = library;
    mBookExist = bookExist; //Used to check if a book exists in the library
}

Library::~Library(){ //Destructor
    delete mLibrary;
    std::cout << "Library was deleted";
}

void Library::addBook(){ //Adds books to the library
    ignoreBuffer(); //In error_handling.cpp, clears the buffer
    std::string title;
    std::string author;
    setBookExist(false);

    std::cout << "ADD BOOKS" << std::endl << std::endl;

    std::cout << "Insert book title or write '0' to go back to menu ";
    std::getline(std::cin, title);

    if(title == "0"){
        return;
    }

    std::cout << "Who is the author of the book you want to add? ";
    std::getline(std::cin, author);

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
        std::cout << title << " by " << author << " was added to library." << std::endl;
    }
}

void Library::lendABook(){ //Lends out books
    ignoreBuffer();
    std::cout << "LEND OUT BOOKS" << std::endl << std::endl;
    int amountOfBooks = insertAmountOfBooks(); //In error_handling.cpp, checks so input is correct
    Book* pBook; //A pointer to the Book objects

    if(amountOfBooks == 0){
        return;
    }
    else if(amountOfBooks > 1){ //Several books
        std::vector<std::string>* titlesList = new std::vector<std::string>; //Stores the list of books the user input
        severalBooks(titlesList, amountOfBooks); //In library.cpp
        
        for(int i = 0; i < titlesList->size(); i++){ //Loops through the titleList[] and checks if the book is in library
            for(int j = 0; j < mLibrary->size(); j++){
                pBook = &(*mLibrary)[j];
                if((*titlesList)[i] == pBook->getTitle() && pBook->getAvailable() == true){
                    pBook->borrowBook();
                    std::cout << pBook->getTitle() << " by " << pBook->getAuthor() << " was borrowed." << std::endl;
                    break;
                }
                else if((*titlesList)[i] == pBook->getTitle() && pBook->getAvailable() == false){
                    std::cout << pBook->getTitle() << " is already borrowed." << std::endl;
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
        ignoreBuffer();
        std::string whatTitle;
        setBookExist(false);
        do{
            std::cout << "What book do you want to lend out? ";
            std::getline(std::cin, whatTitle);
            
            checkIfBookExist(&whatTitle); //In library.cpp
        }while(!getBookExist());

        for(int i = 0; i <= mLibrary->size() - 1; i++){
            pBook = &(*mLibrary)[i];
            if(whatTitle == pBook->getTitle() && pBook->getAvailable() == true){
                pBook->borrowBook();
                std::cout << pBook->getTitle() << " by " << pBook->getAuthor() << " was borrowed." << std::endl;
                break;
            }
            else if(whatTitle == pBook->getTitle() && pBook->getAvailable() == false){
                std::cout << pBook->getTitle() << " is already borrowed." << std::endl;
                break;
            }
            else if(i == (*mLibrary).size() - 1){
                std::cout << whatTitle << " does not exist" << std::endl;
            }
        }
    }
}

void Library::returnABook(){ //Returns books
    ignoreBuffer();  
    std::cout << "RETURN BOOKS" << std::endl << std::endl;
    int amountOfBooks = insertAmountOfBooks();   
    Book* pBook;  

    if(amountOfBooks == 0){
        return;
    }
    else if(amountOfBooks > 1){ //Several Books
        std::vector<std::string>* titlesList = new std::vector<std::string>;
        severalBooks(titlesList, amountOfBooks);
        for(int i = 0; i < titlesList->size(); i++){
            for(int j = 0; j < mLibrary->size(); j++){
                pBook = &(*mLibrary)[j];
                if((*titlesList)[i] == pBook->getTitle() ){
                    pBook->returnBook();
                    std::cout << pBook->getTitle() << " by " << pBook->getAuthor() << " was returned." << std::endl;
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
        ignoreBuffer();
        std::string whatTitle;
        setBookExist(false);
        do{
            std::cout << "What book do you want to return? ";
            std::getline(std::cin, whatTitle);
            checkIfBookExist(&whatTitle);
        }while(!getBookExist());

        for(int i = 0; i <= mLibrary->size() - 1; i++){
            pBook = &(*mLibrary)[i];
            if(whatTitle == pBook->getTitle()){
                pBook->returnBook();
                std::cout << pBook->getTitle() << " by " << pBook->getAuthor() << " was returned." << std::endl;
                break;
            }
            else if(i == (*mLibrary).size() - 1){
                std::cout << whatTitle << " does not exist" << std::endl;
            }
        }
    }
}

void Library::severalBooks(std::vector <std::string> *titlesList, int amountOfBooks){ //Handles if multiple books is lended or borrowed
    ignoreBuffer();
    std::string bookTitle;
    std::stringstream ss;
    for(int i = 0; i < amountOfBooks; i++){
        std::cout << "Insert book title " << i+1 << std::endl;
        std::getline(std::cin, bookTitle);
        ss << bookTitle << ';';
    }

    std::string allTitles = ss.str();

    int listIndex = 0;
    int wordStart = 0;

    for(int i = 0; i < allTitles.length(); i++){ //Loops through the file and add the book titles to titlesList[]
        if(allTitles[i] == ';' || i == allTitles.length() - 1){
            std::string sub = allTitles.substr(wordStart, i-wordStart);
            titlesList->push_back(sub);
            wordStart = i+1;
        }
    }
}

void Library::displayBooks(){ //Displays the books in library
    std::cout << "DISPLAY BOOKS" << std::endl << std::endl;
    std::cout << std::left << std::setw(20) << "TITLE" << std::right << std::setw(20) << "AUTHOR" << std::setw(20) <<  "AVAILABLE" << std::endl;
        for(int i = 0; i < mLibrary->size(); i++){
            Book *pBook;
            pBook = &(*mLibrary)[i];
            pBook->displayDetails();
        }
}

void Library::checkIfBookExist(std::string* whatTitle){ //Checks if a book exists in the library
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

void Library::loadToLibrary(std::fstream &inOutFile){ //Checks library.txt, creates the Book objects and add them to the library
    std::string line;
    std::string title;
    std::string author;
    bool isAvailable;
    int lineCount = 1; //Keeps track of the amount of lines

    while(std::getline(inOutFile, line)){  
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
            else if(line == " No"){
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

void Library::saveToFile(std::fstream &inOutFile){ //Saves the library to library.txt
    Book* pBook;

    for(int i = 0; i < mLibrary->size(); i++){
        pBook = &(*mLibrary)[i];
        inOutFile << pBook->getTitle() << std::endl;
        inOutFile << pBook->getAuthor() << std::endl;

        if(pBook->getAvailable()){
            inOutFile << "Yes";
        }
        else{
            inOutFile << " No";
        }

        if(i < mLibrary->size()-1){ //Adds new line after every string excepts last one
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