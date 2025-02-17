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

float simpson_integral(float xl, float xr, float n, function_t f) {
    float sum = 0;
    float h = (xr - xl) / n;

    for (float x = xl + h; x < xr - h; x += h) {
        float step = h / 6.0 * (f(x) + 4.0 * f(0.5 * (x + x + h)) + f(x + h));
        sum += step;
    }
    return sum;
}

float integral(float xl, float xr, float eps, function_t f) {
    float n = 1000;
    float e = fabs(simpson_integral(xl, xr, 2 * n, f) - simpson_integral(xl, xr, n, f));

    while (e >= eps) {
        n *= 2;
        e = fabs(simpson_integral(xl, xr, 2 * n, f) - simpson_integral(xl, xr, n, f));
    }

    return simpson_integral(xl, xr, n, f);
}