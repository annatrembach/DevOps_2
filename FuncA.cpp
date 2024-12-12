#include "FuncA.h"
#include <cmath>
#include <vector>
#include <algorithm>

int factorial(int n) {
    if (n <= 1) return 1;
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

std::vector<double> FuncA::calculateTrigValues(int numValues) {
    std::vector<double> results;
    
    for (int i = 0; i < numValues; ++i) {
        double angle = i * (M_PI / 180.0);  

        double sinValue = 0;
        for (int j = 0; j < 10; ++j) {  
            sinValue += pow(-1, j) * pow(angle, 2 * j + 1) / factorial(2 * j + 1);
        }

        results.push_back(sinValue); 
    }

    std::sort(results.begin(), results.end());

    return results;
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

