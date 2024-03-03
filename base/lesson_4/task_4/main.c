/*
Определить уравнение прямой по координатам двух точек. Уравнение вида y=k*x+b
Данные на входе:    	Четыре целых числа через пробел. Координаты X1 Y1 X2 Y2
Данные на выходе:     Два числа k,b в формате "%.2f %.2f"

Пример №1
Данные на входе:      	6 9 -1 3
Данные на выходе:     0.86 3.86

Пример №2
Данные на входе:     	1 2 3 4
Данные на выходе:     1.00 1.00
 */

#include <stdio.h>

int main() {
    int p1x = 0, p1y = 0, p2x = 0, p2y = 0;

    if (scanf("%d", &p1x) != 1)
        return 1;

    if (scanf("%d", &p1y) != 1)
        return 1;

    if (scanf("%d", &p2x) != 1)
        return 1;

    if (scanf("%d", &p2y) != 1)
        return 1;

    float dy = p2y - p1y;
    float dx = p2x - p1x;

    float k = dy / dx;
    float b = p2y - k * p2x;

    printf("%.2f %.2f\n", k, b);

    return 0;
}
