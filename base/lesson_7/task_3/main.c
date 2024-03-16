/*
 Количество 1
Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.
Данные на входе: 		Натуральное число
Данные на выходе: 	Целое число - количество единиц в двоичной записи числа.

Пример №1
Данные на входе: 		5
Данные на выходе: 	2

Пример №2
Данные на входе: 		255
Данные на выходе: 	8
 */

#include <stdio.h>

int amountSetBits(unsigned n) {
    static int count = 0;
    if (n != 0) {
        count += n % 2;
        amountSetBits(n / 2);
    }
    return count;

}

int main(void) {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    printf("%d\n", amountSetBits(digit));
}
