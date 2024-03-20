/* e5.c
 *
 *  Считать массив из 10 элементов и  посчитать сумму положительных элементов массива
 *
 */

#include <stdio.h>

int summ_positive(int source[], int source_size) {
    int summ = 0;
    for (int i = 0; i < source_size; i++) {
        if (source[i] > 0)
            summ += source[i];
    }

    return summ;
}

int main(void) {
    enum {
        INPUT_LIMIT = 10
    };

    int source_data[INPUT_LIMIT] = {0};
    int i = 0;

    while (i < INPUT_LIMIT) {
        if (scanf("%d", &source_data[i]) == 1)
            i++;
    }

    printf("%d", summ_positive(source_data, INPUT_LIMIT));

    return 0;
}
