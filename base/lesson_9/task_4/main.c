/* f6.c
 *
 *  Написать логическую функцию которая определяет, верно ли, что среди элементов массива есть два одинаковых
 *
 */

#include <stdio.h>

int frequency_digit(int source[], int digit, int l, int r) {
    int count = 0;
    l = l > r ? r : l;
    for (int i = l; i < r; i++) {
        if (source[i] == digit)
            count++;
    }

    return count;
}

int is_two_same(int source_size, int source[]) {
    for (int i = 0; i < source_size; i++) {
        if (frequency_digit(source, source[i], i, source_size) > 1)
            return 1;
    }

    return 0;
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

    _Bool double_include_exists = is_two_same(INPUT_LIMIT, source_data);

    printf("%s", double_include_exists ? "YES" : "NO");

    return 0;
}
