#include "FuncA.h"
#include <cmath> 

double FuncA::calculate(int n) {
    // This function calculates the sum of the first n terms of the infinite series
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double term = pow(-1, i) * (pow(2, i) * factorial(2 * i)) / (pow(4, i) * pow(factorial(i), 2) * (2 * i + 1));
        sum += term;
    }
    return sum;
}

double FuncA::factorial(int num) {
    if (num == 0 || num == 1) return 1;
    double fact = 1;
    for (int i = 2; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

