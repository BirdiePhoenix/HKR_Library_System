#include "file_manager.h"
#include <iostream>

void checkIfOpen(){
    std::fstream inOutFile("library.txt", std::ios::in | std::ios::out);

    if(!inOutFile)
        std::cout << "Failed to open library.txt for reading" << std::endl;

    if(inOutFile.is_open()){
        std::cout << "is_open() flag got triggered" << std::endl;
        inOutFile.close();
    }
    else{
        std::cerr << "Error opening file" << std::endl;
    }
}
