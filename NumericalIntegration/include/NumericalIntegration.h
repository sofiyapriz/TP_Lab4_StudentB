#pragma once

#ifdef NUMERICALINTEGRATION_EXPORTS
    #define NUMERICALINTEGRATION_API extern "C" __declspec(dllexport)
#else
    #define NUMERICALINTEGRATION_API extern "C" __declspec(dllimport)
#endif

typedef double (*MathFunc)(double);

NUMERICALINTEGRATION_API double rectangle(MathFunc f, double a, double b, int steps);
NUMERICALINTEGRATION_API double trapezoid(MathFunc f, double a, double b, int steps);
NUMERICALINTEGRATION_API double simpson(MathFunc f, double a, double b, int steps);
NUMERICALINTEGRATION_API double integrationError(double coarseValue, double fineValue, int orderOfAccuracy);
