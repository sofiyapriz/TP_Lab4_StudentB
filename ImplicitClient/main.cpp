#include <iostream>
#include <iomanip>
#include <cmath>
#include "NumericalIntegration.h"

double testFunc(double x) { return x * x; }

int main() {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "=== [Implicit Linking] Partner Library Test ===\n\n";
    double a = 0.0, b = 3.0;
    int steps = 1000;
    std::cout << "Integrating f(x) = x^2 on [0, 3] (Exact: 9.000000)\n\n";
    std::cout << "Rectangle method : " << rectangle(testFunc, a, b, steps) << "\n";
    std::cout << "Trapezoid method : " << trapezoid(testFunc, a, b, steps) << "\n";
    std::cout << "Simpson method   : " << simpson(testFunc, a, b, steps) << "\n\n";
    std::cout << "--- Edge Cases Testing ---\n";
    std::cout << "nullptr test (safe NaN): " << rectangle(nullptr, a, b, steps) << "\n";
    std::cout << "steps = 0 test (safe NaN): " << trapezoid(testFunc, a, b, 0) << "\n";
    return 0;
}
