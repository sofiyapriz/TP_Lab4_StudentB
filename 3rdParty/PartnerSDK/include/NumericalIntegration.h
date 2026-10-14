#ifndef NUMERICAL_INTEGRATION_H
#define NUMERICAL_INTEGRATION_H

#ifdef _WIN32
    #ifdef NUMERICALINTEGRATION_EXPORTS
        #define NUMERICALINTEGRATION_API __declspec(dllexport)
    #else
        #define NUMERICALINTEGRATION_API __declspec(dllimport)
    #endif
#else
    #define NUMERICALINTEGRATION_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef double (*MathFunc)(double);

NUMERICALINTEGRATION_API double rectangle(MathFunc f, double a, double b, int steps);
NUMERICALINTEGRATION_API double trapezoid(MathFunc f, double a, double b, int steps);
NUMERICALINTEGRATION_API double simpson(MathFunc f, double a, double b, int steps);
NUMERICALINTEGRATION_API double integrationError(double coarseValue, double fineValue, int orderOfAccuracy);

#ifdef __cplusplus
}
#endif

#endif // NUMERICAL_INTEGRATION_H
