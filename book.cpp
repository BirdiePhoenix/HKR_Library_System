#include "book.h"
#include <iostream>

Book::Book(std::string title, std::string author, bool isAvailable){
    mTitle = title;
    mAuthor = author;
    mIsAvailable = isAvailable;
}

void Book::displayDetails(){
    std::string printAvailable;

    if(mIsAvailable)
        printAvailable = "Available";
    else
        printAvailable = "Not Available";

    std::cout << getTitle() << "     " << getAuthor() << "     " << printAvailable << std::endl;
}

void Book::borrowBook(){

}

void Book::returnBook(){

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