/* f5.c
 *
 *  Написать функцию которая находит максимальный элемент в массиве
 *
 */

#include <stdio.h>

int find_max_array(int source_size, int source[]) {
    int max_value = source[0];
    for (int i = 1; i < source_size; i++) {
        if (source[i] > max_value) {
            max_value = source[i];
        }
    }

    return max_value;
}

int main(void) {
    enum {
        INPUT_LIMIT = 100
    };

    int source_data[INPUT_LIMIT] = {0};
    int i = 0;

    while (i < INPUT_LIMIT) {
        if (scanf("%d", &source_data[i]) == 1)
            i++;
    }

    int max_value = find_max_array(INPUT_LIMIT, source_data);

    printf("%d", max_value);

    return 0;
}
