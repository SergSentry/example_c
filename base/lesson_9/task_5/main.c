/* f2.c
 *
 *  Написать функцию, которая ставит в начало массива все четные элементы, а в конец все нечетные
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

int abs(int value) {
    return value < 0 ? -value : value;
}

void sort_even_odd(int size, int source[]) {
    int current;
    int next;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            current = abs(source[j]);
            next = abs(source[j + 1]);
            if (current % 2 != 0 && next % 2 == 0) {
                int tmp = source[j];
                source[j] = source[j + 1];
                source[j + 1] = tmp;
            }
        }
    }
}

int main(void) {
    enum {
        INPUT_LIMIT = 20
    };

    int source_data[INPUT_LIMIT] = {0};
    int i = 0;

    while (i < INPUT_LIMIT) {
        if (scanf("%d", &source_data[i]) == 1)
            i++;
    }

    sort_even_odd(INPUT_LIMIT, source_data);

    print_array(source_data, INPUT_LIMIT);

    return 0;
}
