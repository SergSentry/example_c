/* e13.c
 *
 *  Считать массив из 10 элементов и отобрать в другой массив все числа,
 *  у которых вторая с конца цифра ноль
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

_Bool is_second_from_end_zero(int a) {
    int tmp = (a % 100);
    return (tmp >= 0) && (tmp <= 9);
}

void select(int source[], int source_size, int target[], int *target_size) {
    *target_size = 0;
    for (int i = 0; i < source_size; i++) {
        if (is_second_from_end_zero(source[i]))
            target[(*target_size)++] = source[i];
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

    int target[INPUT_LIMIT] = {0};
    int target_size = 0;

    select(source_data, INPUT_LIMIT, target, &target_size);

    print_array(target, target_size);

    return 0;
}
