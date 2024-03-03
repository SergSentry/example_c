/*
 Ввести пять чисел и  вывести наименьшее из них
Нужно напечатать наименьшее число

Данные на входе:     Пять целых чисел разделенных пробелом
Данные на выходе:    Одно целое число

Данные на входе:      4    15    9    56    4
Данные на выходе:     4

 */

#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0, d = 0, e = 0;

    if (scanf("%d", &a) != 1)
        return 1;

    if (scanf("%d", &b) != 1)
        return 1;

    if (scanf("%d", &c) != 1)
        return 1;

    if (scanf("%d", &d) != 1)
        return 1;

    if (scanf("%d", &e) != 1)
        return 1;

    int min_ab = a < b ? a : b;
    int min_cd = c < d ? c : d;
    int min_abcd = min_ab < min_cd ? min_ab : min_cd;
    int min = min_abcd < e ? min_abcd : e;

    printf("%d\n", min);
    return 0;
}
