/*
 Ввести пять чисел и  вывести наибольшее из них
Нужно напечатать наибольшее число

Данные на входе:     Пять целых чисел разделенных пробелом
Данные на выходе:    Одно целое число

Данные на входе:      4    15    9    56    4
Данные на выходе:     56

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

    int max_ab = a < b ? b : a;
    int max_cd = c < d ? d : c;
    int max_abcd = max_ab < max_cd ? max_cd : max_ab;
    int max = max_abcd < e ? e : max_abcd;

    printf("%d\n", max);

    return 0;
}
