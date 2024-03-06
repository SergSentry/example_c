/*
 Перевернуть число
Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.

Данные на входе:	Целое неотрицательное число
Данные на выходе:	Целое не отрицательное число наоборот

Пример №1
Данные на входе:	1234
Данные на выходе:	4321

Пример №2
Данные на входе:	782
Данные на выходе:	287
 */

#include <stdio.h>

int main() {
    int source_digit = 0;

    if (scanf("%d", &source_digit) != 1)
        return 1;

    if (source_digit < 0)
        return 1;

    if (source_digit == 0) {
        printf("%d", source_digit);
        return 0;
    }

    // расчет кол-ва разрядов в числе
    int i_digit = source_digit;
    int digit_len = 0;
    while (i_digit > 0) {
        i_digit -= (i_digit % 10);
        i_digit /= 10;
        digit_len++;
    }

    // расчет множетеля разряда
    int position = 1;
    for (int i = 0; i < digit_len - 1; i++)
        position *= 10;

    // поворот числа
    int result_digit = 0;
    i_digit = source_digit;
    while (i_digit > 0) {
        int current_number = i_digit % 10;
        i_digit -= current_number;
        i_digit /= 10;
        result_digit += current_number * position;
        position /= 10;
    }

    printf("%d", result_digit);
    return 0;
}
