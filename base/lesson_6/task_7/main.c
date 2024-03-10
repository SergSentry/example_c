/*
 Сумма цифр равна произведению

Составить логическую функцию, которая определяет, верно ли, что в данном числе сумма цифр равна произведению.

int is_happy_number(int n)

Данные на входе: 	Целое не отрицательное число
Данные на выходе: 	YES или NO

Пример №1
Данные на входе: 	123
Данные на выходе: 	YES

Пример №2
Данные на входе: 	528
Данные на выходе: 	NO
 */

#include <stdio.h>

_Bool is_happy_number(int digit) {
    int summ = 0;
    int mult = 1;

    while (digit > 0) {
        int current_number = digit % 10;
        digit -= current_number;
        digit /= 10;
        summ += current_number;
        mult *= current_number;
    }

    return summ == mult;
}

int main(void) {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    if (is_happy_number(digit))
        printf("YES");
    else
        printf("NO");
}
