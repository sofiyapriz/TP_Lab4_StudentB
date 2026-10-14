#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>

typedef double (*MathFunc)(double);
typedef double (*RectFunc)(MathFunc, double, double, int);
typedef double (*TrapFunc)(MathFunc, double, double, int);
typedef double (*SimpFunc)(MathFunc, double, double, int);
typedef double (*ErrFunc)(double, double, int);

double testFunc(double x) { return x * x; }

int main() {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "=== [Explicit Linking] WinAPI Dynamic Loading ===\n\n";
    HMODULE hLib = LoadLibrary(TEXT("NumericalIntegration.dll"));
    if (!hLib) {
        std::cerr << "ERROR: Failed to load NumericalIntegration.dll!\n";
        return 1;
    }
    std::cout << "[OK] DLL successfully loaded into memory!\n\n";

    auto rect = reinterpret_cast<RectFunc>(GetProcAddress(hLib, "rectangle"));
    auto trap = reinterpret_cast<TrapFunc>(GetProcAddress(hLib, "trapezoid"));
    auto simp = reinterpret_cast<SimpFunc>(GetProcAddress(hLib, "simpson"));

    if (!rect || !trap || !simp) {
        std::cerr << "ERROR: Failed to find function signatures in DLL export table!\n";
        FreeLibrary(hLib);
        return 1;
    }

    double a = 0.0, b = 3.0;
    int steps = 1000;
    std::cout << "Integrating f(x) = x^2 on [0, 3] (Exact: 9.000000)\n";
    std::cout << "Rectangle: " << rect(testFunc, a, b, steps) << "\n";
    std::cout << "Trapezoid: " << trap(testFunc, a, b, steps) << "\n";
    std::cout << "Simpson  : " << simp(testFunc, a, b, steps) << "\n\n";

    std::cout << "--- Edge Cases Testing ---\n";
    std::cout << "nullptr call: " << rect(nullptr, a, b, steps) << "\n";
    std::cout << "steps = -5  : " << trap(testFunc, a, b, -5) << "\n\n";

    FreeLibrary(hLib);
    std::cout << "[OK] Library unloaded from memory successfully.\n";
    return 0;
}
