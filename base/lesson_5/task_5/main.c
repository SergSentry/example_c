/*
 Все цифры четные
Ввести целое число и определить, верно ли, что все его цифры четные.
Данные на входе:	Одно целое число
Данные на выходе:	YES или NO

Пример №1
Данные на входе:	2684
Данные на выходе:	YES

Пример №2
Данные на входе:	2994
Данные на выходе:	NO
 */

#include <stdio.h>

int main() {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    if (digit == 0) {
        printf("NO");
        return 0;
    }

    while (digit > 0) {
        int current_number = digit % 10;
        digit -= current_number;
        digit /= 10;
        if (current_number & 1) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}
