#include <iostream>
#include <iomanip>
#include <cmath>
#include "NumericalDiff.h"

double cube(double x) { return x * x * x; }
double sine(double x) { return std::sin(x); }

int main() {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "=== Numerical Differentiation DLL Test (Student B) ===\n\n";
    double x = 2.0; double h = 0.001;
    std::cout << "Testing f(x) = x^3 at point x = " << x << "\n";
    std::cout << "Exact f'(2)  = 12.000000\n";
    std::cout << "Forward diff : " << forwardDifference(cube, x, h) << "\n";
    std::cout << "Backward diff: " << backwardDifference(cube, x, h) << "\n";
    std::cout << "Central diff : " << centralDifference(cube, x, h) << "\n";
    std::cout << "Exact f''(2) = 12.000000\n";
    std::cout << "Second deriv : " << secondDerivative(cube, x, h) << "\n\n";
    return 0;
}
