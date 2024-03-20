/* e11.c
 *
 *  Считать массив из 10 элементов и отсортировать его по последней цифре
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

_Bool more(int a, int b) {
    return (a % 10) > (b % 10);
}

void bubble_sort(int source[], int l, int r) {
    for (int i = l; i < r; i++) {
        for (int j = r; j > i; j--) {
            if (more(source[j - 1], source[j])) {
                int tmp = source[j - 1];
                source[j - 1] = source[j];
                source[j] = tmp;
            }
        }
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

    bubble_sort(source_data, 0, INPUT_LIMIT - 1);

    print_array(source_data, INPUT_LIMIT);

    return 0;
}
