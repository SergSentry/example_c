/*
 Напечатать сумму максимума и минимума.

Данные на входе:	 Пять целых чисел через пробел
Данные на выходе:    Одно целое число - сумма максимума и минимума

Пример
Данные на входе:      4    15    9    56    4
Данные на выходе:     60

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

    int ab = a < b ? b : a;
    int cd = c < d ? d : c;
    int abcd = ab < cd ? cd : ab;
    int max = abcd < e ? e : abcd;

    ab = a < b ? a : b;
    cd = c < d ? c : d;
    abcd = ab < cd ? ab : cd;
    int min = abcd < e ? abcd : e;

    printf("%d\n", min + max);

    return 0;
}
