/*
 Все счастливые числа
Ввести натуральное число и напечатать все числа от 10 до введенного числа - у которых сумма цифр равна произведению цифр
Данные на входе:		Одно натуральное число большее 10
Данные на выходе:	Числа у которых сумма цифр равна произведению цифр через пробел в порядке возрастания. Не превосходящие введенное число.

Пример №1
Данные на входе:	200
Данные на выходе:	22 123 132

Пример №2
Данные на входе:	1000
Данные на выходе:	22 123 132 213 231 312 321

Пример №3
Данные на входе:	22
Данные на выходе:	22
 */

#include <stdio.h>

int main() {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    if (digit == 0)
        return 1;

    for (int i = 10, i_print = 0; i <= digit; i++) {
        int i_digit = i;
        int summ = 0;
        int mult = 1;

        while (i_digit > 0) {
            int current_number = i_digit % 10;
            i_digit -= current_number;
            i_digit /= 10;
            summ += current_number;
            mult *= current_number;
        }

        if (summ != 0 && mult != 0 && summ == mult) {
            if (i != digit - 1)
                printf("%d ", i);
            else
                printf("%d", i);
        }
    }

    return 0;
}
