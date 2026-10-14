#include "NumericalIntegration.h"
#include <cmath>
#include <limits>

NUMERICALINTEGRATION_API double rectangle(MathFunc f, double a, double b, int steps) {
    if (!f || steps <= 0) return std::numeric_limits<double>::quiet_NaN();
    double h = (b - a) / steps;
    double sum = 0.0;
    for (int i = 0; i < steps; ++i) sum += f(a + (i + 0.5) * h);
    return sum * h;
}

NUMERICALINTEGRATION_API double trapezoid(MathFunc f, double a, double b, int steps) {
    if (!f || steps <= 0) return std::numeric_limits<double>::quiet_NaN();
    double h = (b - a) / steps;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < steps; ++i) sum += f(a + i * h);
    return sum * h;
}

NUMERICALINTEGRATION_API double simpson(MathFunc f, double a, double b, int steps) {
    if (!f || steps <= 0) return std::numeric_limits<double>::quiet_NaN();
    if (steps % 2 != 0) steps++;
    double h = (b - a) / steps;
    double sum = f(a) + f(b);
    for (int i = 1; i < steps; ++i) sum += (i % 2 == 0 ? 2.0 : 4.0) * f(a + i * h);
    return sum * (h / 3.0);
}

NUMERICALINTEGRATION_API double integrationError(double coarseValue, double fineValue, int orderOfAccuracy) {
    if (orderOfAccuracy <= 0) return std::numeric_limits<double>::quiet_NaN();
    return std::abs(fineValue - coarseValue) / (std::pow(2.0, orderOfAccuracy) - 1.0);
}
