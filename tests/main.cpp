#include <iostream>
#include "FuncA.h"

int main() {
  
    FuncA funcA;
    double result = funcA.calculate(); 

    const double expected = 0.9667;
    if (std::abs(result - expected) < 0.0001) {  
        std::cout << "testCalculate PASSED\n";
    } else {
        std::cout << "testCalculate FAILED. Expected " << expected << " but got " << result << "\n";
    }

    return 0;
}

