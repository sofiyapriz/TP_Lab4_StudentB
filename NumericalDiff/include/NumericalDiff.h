#pragma once

namespace NumericalDiff {
    using MathFunc = double(*)(double);

    double forwardDifference(MathFunc f, double x, double h);
    double backwardDifference(MathFunc f, double x, double h);
    double centralDifference(MathFunc f, double x, double h);
    double secondDerivative(MathFunc f, double x, double h);
}
