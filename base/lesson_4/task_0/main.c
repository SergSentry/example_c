/*
Ввести два числа и вывести их в порядке возрастания.

Данные на входе:     Два целых числа
Данные на выходе:    Два целых числа

Пример:
Данные на входе:    15 9
Данные на выходе:   9 15

 */

#include <stdio.h>

int main() {
    int a = 0, b = 0;

    if (scanf("%d", &a) != 1)
        return 1;

    if (scanf("%d", &b) != 1)
        return 1;

    if (a < b)
        printf("%d %d\n", a, b);
    else
        printf("%d %d\n", b, a);

    return 0;
}
