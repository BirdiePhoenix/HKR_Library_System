#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H
#include <iostream>
#include <limits>
#include <fstream>

int intChecker();
void ignoreBuffer();
int insertAmountOfBooks();
void checkIfOpen(std::fstream &inOutFile);

#endif