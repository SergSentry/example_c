/*
Дано трехзначное число, напечатать максимальную цифру

Данные на входе:      Целое положительное трехзначное число
Данные на выходе:     Одна цифра

Пример
Данные на входе:     435
Данные на выходе:    5

 */

#include <stdio.h>

int main() {
    int a = 0;

    if (scanf("%d", &a) != 1)
        return 1;

    int first_digit = a / 100;
    int second_digit = (a / 10) % 10;
    int third_digit = a % 10;

    if (first_digit < third_digit && second_digit < third_digit)
        printf("%d\n", third_digit);
    else if (first_digit < second_digit)
        printf("%d\n", second_digit);
    else
        printf("%d\n", first_digit);

    return 0;
}
