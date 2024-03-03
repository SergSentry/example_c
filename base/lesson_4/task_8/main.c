/*
 Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.

Данные на входе:      Три целых числа
Данные на выходе:     Одно слово YES или NO

Пример
Данные на входе:      4 5 17
Данные на выходе:     YES

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
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
