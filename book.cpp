#include "book.h"
#include <iostream>
#include <iomanip>

Book::Book(std::string title, std::string author, bool isAvailable){
    mTitle = title;
    mAuthor = author;
    mIsAvailable = isAvailable;
}

void Book::displayDetails(){
    std::string printAvailable;

    if(getAvailable())
        printAvailable = "Yes";
    else
        printAvailable = "No";

    std::cout << std::left << std::setw(20) << getTitle() << std::right << std::setw(20) << getAuthor() << std::setw(20) << printAvailable << std::endl;
}

void Book::borrowBook(){
    if(getAvailable()){
        setAvailable(false);
        displayDetails();
    }
    else    
        std::cout << mTitle << " is already borrowed." << std::endl;
}

void Book::returnBook(){
    setAvailable(true);
    displayDetails();
}

std::string Book::getTitle(){
    return mTitle;
}

std::string Book::getAuthor(){
    return mAuthor;
}

bool Book::getAvailable(){
    return mIsAvailable;
}

void Book::setAvailable(bool isAvailable){
    mIsAvailable = isAvailable;
}