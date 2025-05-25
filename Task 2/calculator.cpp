// calculator.cpp
#include <cstring>
#include <cstdlib>

extern "C" {
    __declspec(dllexport) double calculate(const char* expr);
}

double calculate(const char* expr) {
    double result = 0;
    char op = 0;
    char* exprCopy = _strdup(expr);
    char* token = strtok(exprCopy, "+-*/");

    if (token) result = atof(token);
    token = strtok(nullptr, "+-*/");

    if (token) {
        const char* opPos = strpbrk(expr, "+-*/");
        if (opPos) op = *opPos;
        double b = atof(token);
        switch (op) {
            case '+': result += b; break;
            case '-': result -= b; break;
            case '*': result *= b; break;
            case '/': result = b != 0 ? result / b : 0; break;
        }
    }

    free(exprCopy);
    return result;
}
