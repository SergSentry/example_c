/*
 Ввести номер месяца и вывести название времени года.

Данные на входе:    	Целое число от 1 до 12 - номер месяца.
Данные на выходе:     Время года на английском: winter, spring, summer, autumn (используйте switch)

Пример №1
Данные на входе:      4
Данные на выходе:     spring

Пример №2
Данные на входе:     1
Данные на выходе:    winter

 */

#include <stdio.h>

int main() {
    int month_number = 0;

    if (scanf("%d", &month_number) != 1)
        return 1;

    if (month_number < 0 && month_number > 12)
        return 1;

    int season = month_number / 3;

    if (season == 0 || season == 4)
        printf("winter\n");
    else if (season == 1)
        printf("spring\n");
    else if (season == 2)
        printf("summer\n");
    else if (season == 3)
        printf("autumn\n");

    return 0;
}
