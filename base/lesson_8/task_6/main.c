/* e12.c
 *
 *  Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую по убыванию
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
    return a > b;
}

_Bool less(int a, int b) {
    return a < b;
}

void bubble_sort_more(int source[], int l, int r) {
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

void bubble_sort_less(int source[], int l, int r) {
    for (int i = l; i < r; i++) {
        for (int j = r; j > i; j--) {
            if (less(source[j - 1], source[j])) {
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

    int half_size = INPUT_LIMIT / 2;

    bubble_sort_more(source_data, 0, half_size - 1);
    bubble_sort_less(source_data, half_size, INPUT_LIMIT - 1);

    print_array(source_data, INPUT_LIMIT);

    return 0;
}
