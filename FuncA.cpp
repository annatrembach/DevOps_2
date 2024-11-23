#include "FuncA.h"

double FuncA::calculate() {
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        double term = pow(-1, i) * (pow(2, i) * factorial(2 * i)) / (pow(4, i) * pow(factorial(i), 2) * (2 * i + 1));
        sum += term;
    }
    return sum;
}

