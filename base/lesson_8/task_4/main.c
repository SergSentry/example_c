/* e10.c
 *
 *  Ввести с клавиатуры массив из 12 элементов и выполнить циклический сдвиг вправо на 4
 *
 */

#include <stdio.h>

void print_array(int source[], int source_size) {
    for (int i = 0; i < source_size; i++) {
        if (i < source_size - 1)
            printf("%d ", source[i]);
        else
            printf("%d", source[i]);
    }
}

void right_shift_by_one(int source[], int source_size) {
    for (int i = source_size - 1; i > 0; i--) {
        int tmp = source[i];
        source[i] = source[i - 1];
        source[i - 1] = tmp;
    }
}

void right_shift_by_four(int source[], int source_size) {
    right_shift_by_one(source, source_size);
    right_shift_by_one(source, source_size);
    right_shift_by_one(source, source_size);
    right_shift_by_one(source, source_size);
}

int main(void) {
    enum {
        INPUT_LIMIT = 12
    };

    int source_data[INPUT_LIMIT] = {0};
    int i = 0;

    while (i < INPUT_LIMIT) {
        if (scanf("%d", &source_data[i]) == 1)
            i++;
    }

    right_shift_by_four(source_data, INPUT_LIMIT);

    print_array(source_data, INPUT_LIMIT);

    return 0;
}
