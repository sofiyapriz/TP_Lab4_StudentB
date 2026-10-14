# NumericalDiff Dynamic Library SDK Package

## Опис контракту API (Design by Contract)
Ця бібліотека містить набір функцій для чисельного диференціювання дійсних функцій однієї змінної.
Всі функції експортовані з угодою C-ABI (без C++ Name Mangling).

### Сигнатури функцій:

double forwardDifference(MathFunc f, double x, double h);
double backwardDifference(MathFunc f, double x, double h);
double centralDifference(MathFunc f, double x, double h);
double secondDerivative(MathFunc f, double x, double h);

де typedef double (*MathFunc)(double);

### Контрактні обмеження та обробка граничних умов (Edge Cases):
1. f не повинен бути nullptr. Якщо передано nullptr, функція безпечно повертає NaN (not-a-number) без аварійного завершення (Crash / Access Violation).
2. Крок h не повинен дорівнювати 0 (або бути меншим за 1e-15). При |h| < 1e-15 повертається NaN.
3. Для обчислення першої похідної найвищу точність O(h^2) забезпечує функція centralDifference.
