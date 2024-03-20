/* e1.c
 *
 *  Ввести с клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива
 *
 */

#include <stdio.h>

float mean(int source[], int source_size) {
    float summ = 0;
    for (int i = 0; i < source_size; i++) {
        summ += source[i];
    }

    return summ / source_size;
}

int main(void) {
    enum {
        INPUT_LIMIT = 5
    };

    int source_data[INPUT_LIMIT] = {0};
    int i = 0;

    while (i < INPUT_LIMIT) {
        if (scanf("%d", &source_data[i]) == 1)
            i++;
    }

    printf("%.3f", mean(source_data, INPUT_LIMIT));

    return 0;
}

