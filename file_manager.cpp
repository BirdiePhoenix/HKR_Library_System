#include "file_manager.h"
#include <iostream>

void checkIfOpen(){
    std::fstream inOutFile("library.txt", std::ios::in | std::ios::out);

    if(!inOutFile)
        std::cout << "Failed to open library.txt for reading" << std::endl;
}
