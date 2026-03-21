#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include <fstream>
#include <iostream>
#include "book.h"

class Library{
    private:
        std::vector <Book> mLibrary;
    public:
        Library(std::vector <Book> library);
        void addBook();
        void lendABook();
        void returnABook();
        void displayBooks();
        void severalBooks(std::vector <std::string> *titlesList);
        void loadToLibrary(std::fstream &inOutFile);
};

#endif