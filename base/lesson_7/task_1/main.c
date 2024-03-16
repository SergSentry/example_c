/*
В прямом порядке
Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками. Необходимо реализовать рекурсивную функцию.

void print_num(int num)

Данные на входе: 		Одно целое неотрицательное число
Данные на выходе: 	Все цифры числа через пробел в прямом порядке.

Пример №1
Данные на входе: 		15
Данные на выходе: 	1 5

Пример №2
Данные на входе: 		54321
Данные на выходе: 	5 4 3 2 1
 */

#include <stdio.h>

void print_num(int digit) {
    if (!digit)
        return;

    // расчет кол-ва разрядов в числе
    int i_digit = digit;
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

    printf("%d\n", digit / position);

    print_num(digit % position);
}

int main(void) {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    if (digit <= 0)
        return 1;

    print_num(digit);

    return 0;
}
