#include "math_function.h"

int signF(float x, function_t f) {
    return f(x) < 0 ? -1 : 1;
}

float rootFindDiv2(float xl, float xr, float eps, function_t f) {
    int step_count = 0;
    float xm;

    while (fabs(xr - xl) > eps) {
        step_count++;
        xm = (xl + xr) / 2;

        if (f(xr) == 0) {
            printf("Найден корень за %d шага\n", step_count);
            return xr;
        }

        if (f(xl) == 0) {
            printf("Найден корень за %d шага\n", step_count);
            return xl;
        }

        if (signF(xl, f) != signF(xm, f))
            xr = xm;
        else
            xl = xm;
    }
    printf("Найден корень за %d шага\n", step_count);
    return (xl + xr) / 2;
}