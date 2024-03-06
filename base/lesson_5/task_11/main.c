/*
 Сумма цифр равна 10
Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.

Данные на входе:		Натуральное число
Данные на выходе:	YES или NO

Пример №1
Данные на входе:	1234
Данные на выходе:	YES

Пример №2
Данные на входе:	1233
Данные на выходе:	NO
 */

#include <stdio.h>

int main() {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    int summ = 0;
    while (digit > 0) {
        int current_number = digit % 10;
        digit -= current_number;
        digit /= 10;
        summ += current_number;
    }

    if (summ == 10)
        printf("YES");
    else
        printf("NO");

    return 0;
}
