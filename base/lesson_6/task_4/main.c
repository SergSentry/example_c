/*
 НОД
Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования.
int nod(int a, int b)
Данные на входе: 	Два целых положительных числа
Данные на выходе: 	Одно целое число - наибольший общий делитель.

Пример №1
Данные на входе: 	14 21
Данные на выходе: 	7
 */

#include <stdio.h>

int nod(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}

int main(void) {
    int first_digit = 0;
    int second_digit = 0;

    if (scanf("%d", &first_digit) != 1)
        return 1;

    if (scanf("%d", &second_digit) != 1)
        return 1;

    printf("%d", nod(first_digit, second_digit));
}
