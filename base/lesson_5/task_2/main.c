/*
Ровно три цифры
Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.

Данные на входе:		Целое положительное число
Данные на выходе:	Одно слово: YES или NO

Пример №1
Данные на входе:	123
Данные на выходе:	YES

Пример №2
Данные на входе:	1234
Данные на выходе:	NO
 */

#include <stdio.h>

int main() {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    if (digit > 99 && digit <= 999)
        printf("YES");
    else
        printf("NO");

    return 0;
}
