#include <iostream>
#include "HTTP_server.h"
#include "FuncA.h" 

int main() {
    std::cout << "Starting HTTP Server..." << std::endl;
   
    int result = CreateHTTPserver();
    
    if (result == 0) {
        std::cout << "Server started successfully!" << std::endl;
    } else {
        std::cerr << "Server failed to start!" << std::endl;
    }
    
    return result;
}

