/*
В обратном порядке
Дано целое неотрицательное число N. Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами или новыми строками.
Данные на входе: 	Одно неотрицательное целое число
Данные на выходе: 	Последовательность цифр введенного числа в обратном порядке через пробел

Пример №1
Данные на входе: 	15
Данные на выходе: 	5 1

Пример №2
Данные на входе: 	54321
Данные на выходе: 	1 2 3 4 5
 */

#include <stdio.h>

void summ_digit(int digit) {
    if (!digit)
        return;

    int last_number = digit % 10;
    digit -= last_number;
    printf("%d ", last_number);

    summ_digit(digit / 10);
}

int main(void) {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    if (digit <= 0)
        return 1;

    summ_digit(digit);

    return 0;
}
