#pragma once

#ifdef NUMERICALDIFF_EXPORTS
    #define NUMERICALDIFF_API extern "C" __declspec(dllexport)
#else
    #define NUMERICALDIFF_API extern "C" __declspec(dllimport)
#endif

typedef double (*MathFunc)(double);

NUMERICALDIFF_API double forwardDifference(MathFunc f, double x, double h);
NUMERICALDIFF_API double backwardDifference(MathFunc f, double x, double h);
NUMERICALDIFF_API double centralDifference(MathFunc f, double x, double h);
NUMERICALDIFF_API double secondDerivative(MathFunc f, double x, double h);
