#include "NumericalDiff.h"
#include <limits>
#include <cmath>

namespace NumericalDiff {
    double forwardDifference(MathFunc f, double x, double h) {
        if (!f || std::abs(h) < 1e-15) return std::numeric_limits<double>::quiet_NaN();
        return (f(x + h) - f(x)) / h;
    }
    double backwardDifference(MathFunc f, double x, double h) {
        if (!f || std::abs(h) < 1e-15) return std::numeric_limits<double>::quiet_NaN();
        return (f(x) - f(x - h)) / h;
    }
    double centralDifference(MathFunc f, double x, double h) {
        if (!f || std::abs(h) < 1e-15) return std::numeric_limits<double>::quiet_NaN();
        return (f(x + h) - f(x - h)) / (2.0 * h);
    }
    double secondDerivative(MathFunc f, double x, double h) {
        if (!f || std::abs(h) < 1e-15) return std::numeric_limits<double>::quiet_NaN();
        return (f(x + h) - 2.0 * f(x) + f(x - h)) / (h * h);
    }
}
