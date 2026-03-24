#include "book.h"
#include <iostream>
#include <iomanip>

Book::Book(std::string title, std::string author, bool isAvailable){ //Constructor
    mTitle = title;
    mAuthor = author;
    mIsAvailable = isAvailable;
}

void Book::displayDetails(){
    std::string printAvailable;

    if(getAvailable()) //Checks if available and prints yes or no instead of true or false
        printAvailable = "Yes";
    else
        printAvailable = "No";

    std::cout << std::left << std::setw(20) << getTitle() << std::right << std::setw(20) << getAuthor() << std::setw(20) << printAvailable << std::endl;
}

void Book::borrowBook(){
    if(getAvailable()){
        setAvailable(false);
    }
}

void Book::returnBook(){
    setAvailable(true);
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