#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H
#include <iostream>
#include <limits>
#include <fstream>

int intChecker();
void ignoreBuffer();
void insertAmountOfBooks(int* amountOfBooksPtr);
void checkIfOpen(std::fstream &inOutFile);
void mainMenuChoice(int* menuChoicePtr);

#endif