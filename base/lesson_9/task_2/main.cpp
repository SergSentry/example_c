/* f9.c
 *
 *  Составить функцию которая находит максимальный из отрицательных элементов и меняет его с последним элементом массива
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

int max(int source[], int source_size, int *max_index) {
    *max_index = 0;
    int max_value = 0;
    for (int i = 0; i < source_size; i++) {
        if (source[i] < 0) {
            if (max_value == 0) {
                max_value = source[i];
                *max_index = i;
            } else if (source[i] > max_value) {
                max_value = source[i];
                *max_index = i;
            }
        }
    }

    return source[*max_index] > 0 ? -1 : *max_index;
}

void swap_negmax_last(int source_size, int source[]) {
    int max_index = 0;
    int max_min = max(source, source_size, &max_index);
    if (max_min > -1) {
        int tmp = source[max_index];
        source[max_index] = source[source_size - 1];
        source[source_size - 1] = tmp;
    }
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

    swap_negmax_last(INPUT_LIMIT, source_data);

    print_array(source_data, INPUT_LIMIT);

    return 0;
}
