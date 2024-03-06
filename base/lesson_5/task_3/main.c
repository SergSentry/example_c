/*
 Две одинаковые цифры рядом
Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом.

Данные на входе:		Одно целое число
Данные на выходе:	Единственное слов: YES или NO

Пример №1
Данные на входе:	1232
Данные на выходе:	NO

Пример №2
Данные на входе:	1224
Данные на выходе:	YES
 */

#include <stdio.h>

int main() {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    int last_number = digit % 10;
    digit -= last_number;
    digit /= 10;

    while (digit > 0) {
        int current_number = digit % 10;
        digit -= current_number;
        digit /= 10;
        if (last_number != current_number)
            last_number = current_number;
        else {
            printf("YES");
            return 0;
        }
    }

    printf("NO");
    return 0;
}
