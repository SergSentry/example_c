/*
 Количество четных и нечетных цифр
Подсчитать количество четных и нечетных цифр числа.

Данные на входе:		Одно целое неотрицательное число.
Данные на выходе:	Два числа через пробел. Количество четных и нечетных цифр в числе.

Пример №1
Данные на входе:	1234
Данные на выходе:	2 2

Пример №2
Данные на входе:	787
Данные на выходе:	1 2
 */

#include <stdio.h>

int main() {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    if (digit < 0)
        return 1;

    if (digit == 0) {
        printf("0 0");
        return 0;
    }

    int odd_number_count = 0;
    int even_number_count = 0;
    while (digit > 0) {
        int current_number = digit % 10;
        digit -= current_number;
        digit /= 10;
        if (current_number & 1)
            odd_number_count++;
        else
            even_number_count++;
    }

    printf("%d %d", even_number_count, odd_number_count);
    return 0;
}
