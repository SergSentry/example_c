/*
 Цифры по возрастанию

Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры стоят по возрастанию. Используя данную функцию решить задачу.

int grow_up(int n)

Данные на входе: 	Одно целое не отрицательное число
Данные на выходе: 	YES или NO

Пример №1
Данные на входе: 	258
Данные на выходе: 	YES

Пример №2
Данные на входе: 	528
Данные на выходе: 	NO
 */

#include <stdio.h>

_Bool is_asc_number_order(int digit) {
    int last_number = digit % 10;
    digit -= last_number;
    digit /= 10;

    while (digit > 0) {
        int current_number = digit % 10;
        digit -= current_number;
        digit /= 10;
        if (last_number >= current_number)
            last_number = current_number;
        else {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    if (is_asc_number_order(digit))
        printf("YES");
    else
        printf("NO");
}
