#ifndef BOOK_H
#define BOOK_H
#include <string>
class Book{
    private:
        std::string mTitle;
        std::string mAuthor;
        bool mIsAvailable;
    public:
        Book(std::string title, std::string author, bool isAvailable);
        void displayDetails();
        void borrowBook();
        void returnBook();
        std::string getTitle();
        std::string getAuthor();
        bool getAvailable();
        void setAvailable(bool isAvailable);
};
#endif