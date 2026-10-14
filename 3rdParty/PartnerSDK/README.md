# Numerical Integration SDK (Variant 1)

## Overview
This SDK provides C-ABI compliant dynamic library (NumericalIntegration.dll) for numerical integration using classical quadrature formulas.

## Package Structure
- include/NumericalIntegration.h - C-compatible header file with exported signatures.
- lib/NumericalIntegration.lib - Import library for implicit linking (MSVC).
- bin/NumericalIntegration.dll - Dynamic Link Library (x64).

## API Specifications
### Types
typedef double (*MathFunc)(double);
Pointer to a continuous single-variable mathematical function.

### Exported Functions
1. double rectangle(MathFunc f, double a, double b, int steps);
2. double trapezoid(MathFunc f, double a, double b, int steps);
3. double simpson(MathFunc f, double a, double b, int steps);
4. double integrationError(double coarseValue, double fineValue, int orderOfAccuracy);

## Edge Cases & Safety Guarantees
1. Null Pointer Safety: Passing f = nullptr returns NaN without process crash.
2. Invalid Step Count: Passing steps <= 0 returns NaN.
3. Simpson Odd Steps: If steps is odd, it is automatically incremented by 1 internally.
4. C-ABI Linkage: All functions are exported with extern "C" linkage (no name mangling).
