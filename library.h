#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include <fstream>
#include <iostream>
#include "book.h"

class Library{
    private:
        std::vector<Book>* mLibrary;
        bool mBookExist;
    public:
        Library(std::vector<Book> library, bool bookExist);
        ~Library();
        void addBook();
        void lendABook();
        void returnABook();
        void displayBooks();
        void checkIfBookExist(std::string* whatTitle);
        void insertBooks(std::vector <std::string> *titlesList, int amountOfBooks);
        void loadToLibrary(std::fstream &inOutFile);
        void saveToFile(std::fstream &inOutFile);
        bool getBookExist();
        void setBookExist(bool bookExist);
};

#endif