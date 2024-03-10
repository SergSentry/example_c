/*
Факториал
Составить функцию вычисления N!. Использовать ее при вычислении факториала
int factorial(int n)

Данные на входе: 	Целое положительное число не больше 20
Данные на выходе: 	Целое положительное число

Пример №1
Данные на входе: 	5
Данные на выходе: 	120
 */

#include <stdio.h>

int factorial(int n) {
    int result_number = 1;
    for (int i = 1; i <= n; i++) {
        result_number *= i;
    }

    return result_number;
}

int main(void) {
    int n = 0;

    if (scanf("%d", &n) != 1)
        return 1;

    if (n < 0 || n > 10)
        return 1;

    printf("%d", factorial(n));

    return 0;
}
