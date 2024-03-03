/*
Ввести три числа и найти наибольшее из них

Данные на входе:	Три целых числа через пробел
Данные на выходе: 	Одно наибольшее целое число

Пример
Данные на входе:	4 15 9
Данные на выходе:  	15
 */

#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0;

    if (scanf("%d", &a) != 1)
        return 1;

    if (scanf("%d", &b) != 1)
        return 1;

    if (scanf("%d", &c) != 1)
        return 1;

    if (a < b && b < c)
        printf("%d\n", c);
    else if (a < c && c < b)
        printf("%d\n", b);
    else
        printf("%d\n", a);

    return 0;
}
