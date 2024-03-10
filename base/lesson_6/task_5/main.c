/*
 Вычислить cos
Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)

cos(x) = 1 - x2/2! + x4/4! - x6/6! + ...
(x в радианах)
float cosinus(float x)

Данные на входе: 	Целое число от 0 до 90
Данные на выходе: 	Вещественное число в формате "%.3f"

Пример
Данные на входе: 	60
Данные на выходе: 	0.500
 */

#include <stdio.h>

const float PI = 3.1415926535F;

float absolut(float digit) {
    return digit < 0.0 ? -digit : digit;
}

float power(float digit, int degree) {
    float result = digit;
    for (int i = 1; i < degree; i++) {
        result *= digit;
    }

    return result;
}

int factorial(int n) {
    int result_number = 1;
    for (int i = 1; i <= n; i++) {
        result_number *= i;
    }

    return result_number;
}

float degree_to_radian(int degree) {
    return (degree * PI) / 180;
}

float cosinus(float x) {
    float summ = 1;
    int step = 1;

    while (1) {
        int mul = 2 * step;
        float member = (power(-1, step) * power(x, mul)) / (float) factorial(mul);

        if (absolut(member) < .001F)
            break;

        summ += member;
        step++;
    }

    return summ;
}

int main(void) {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    if (digit < 0 && digit > 90)
        return 1;

    printf("%.3f", cosinus(degree_to_radian(digit)));
}
