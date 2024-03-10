/*
Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.

Пример №1
Данные на входе: 	Одно целое положительное число N
Данные на выходе: 	Целое число - сумма чисел от 1 до N

Пример №2
Данные на входе: 	100
Данные на выходе: 	5050
 */

#include <stdio.h>

int summ(int count) {
    int result = 0;
    for (int i = 1; i <= count; i++) {
        result += i;
    }

    return result;
}

int main(void) {
    int count = 0;

    if (scanf("%d", &count) != 1)
        return 1;

    printf("%d", summ(count));

    return 0;
}
