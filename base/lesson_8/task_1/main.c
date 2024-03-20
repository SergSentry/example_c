/* e2.c
 *
 *  Ввести с клавиатуры массив из 5 элементов, найти минимальный из них
 *
 */

#include <stdio.h>

int min(int source[], int source_size) {
    int min_value = source[0];
    for (int i = 1; i < source_size; i++) {
        if (source[i] < min_value) {
            min_value = source[i];
        }
    }

    return min_value;
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

    printf("%d", min(source_data, INPUT_LIMIT));

    return 0;
}
