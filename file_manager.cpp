#include "file_manager.h"
#include <iostream>
#include <string>

void checkIfOpen(std::fstream &inOutFile){

    if(!inOutFile)
        std::cout << "Failed to open library.txt for reading" << std::endl;

    if(inOutFile.is_open()){
        std::cout << "is_open() flag got triggered" << std::endl;
    }
    else{
        std::cerr << "Error opening file" << std::endl;
    }
}