/*
Ровно одна цифра 9
Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».
Данные на входе:		Одно целое число
Данные на выходе:	Одно слово: YES или NO

Пример №1
Данные на входе:	193
Данные на выходе:	YES

Пример №2
Данные на входе:	1994
Данные на выходе:	NO
 */

#include <stdio.h>

int main() {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    int nine_counter = 0;
    while (digit > 0) {
        int current_number = digit % 10;
        digit -= current_number;
        digit /= 10;
        if (current_number == 9)
            nine_counter++;
    }

    if (nine_counter > 1 || nine_counter == 0)
        printf("NO");
    else
        printf("YES");

    return 0;
}
