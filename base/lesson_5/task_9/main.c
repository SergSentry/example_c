/*
 Посчитать числа
Дана последовательность ненулевых целых чисел, в конце последовательности число 0.
Подсчитать количество чисел.

Данные на входе:		Целые ненулевые числа. В конце последовательности ноль. Ноль в последовательность не входит.
Данные на выходе:	Одно целое число - количество чисел в последовательности.

Пример №1
Данные на входе:	15 22 2 4 1 6 0
Данные на выходе:	6

Пример №2
Данные на входе:	27 1 3 7 0
Данные на выходе:	4
 */

#include <stdio.h>

int main() {
    int digit = 0;

    if (scanf("%d", &digit) != 1)
        return 1;

    int digit_count = 1;
    while (digit != 0) {
        if (scanf("%d", &digit) != 1)
            return 1;

        if (digit != 0)
            digit_count++;
        else
            break;
    }

    printf("%d", digit_count);

    return 0;
}
