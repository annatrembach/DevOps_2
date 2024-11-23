#include "FuncA.h"  
#include <cmath>    

int factorial(int n) {
    if (n <= 1) return 1;
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double FuncA::calculate() {
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        double term = pow(-1, i) * (pow(2, i) * factorial(2 * i)) /
                      (pow(4, i) * pow(factorial(i), 2) * (2 * i + 1));
        sum += term;
    }
    return sum;
}

