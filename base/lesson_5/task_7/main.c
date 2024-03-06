/*
 Наименьшая и наибольшая цифра
Организовать ввод натурального числа с клавиатуры. Программа должна определить наименьшую и наибольшую цифры, которые входят в состав данного натурального числа.

Данные на входе:		Целое неотрицательное число
Данные на выходе:	Две цифры через пробел. Сначала наименьшая цифра числа, затем наибольшая.

Пример №1
Данные на входе:	15
Данные на выходе:	1 5

Пример №2
Данные на входе:	2457
Данные на выходе:	2 7

Пример №3
Данные на входе:	22
Данные на выходе:	2 2
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

    int min = 10;
    int max = 0;
    while (digit > 0) {
        int current_number = digit % 10;
        digit -= current_number;
        digit /= 10;
        if (current_number > max)
            max = current_number;
        if (current_number < min)
            min = current_number;
    }

    printf("%d %d", min, max);
    return 0;
}
