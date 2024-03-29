/* f4.c
 *
 * Вывести в порядке возрастания цифры, входящие в строку. Цифра - кол-во
 * 
 */

#include <stdio.h>

void print_array(int source[], int source_size) {
    for (int i = 0; i < source_size; i++) {
        if (i < source_size - 1) {
            if (source[i] > 0)
                printf("%d %d\n", i, source[i]);
        } else {
            if (source[i] > 0)
                printf("%d %d", i, source[i]);
        }
    }
}

_Bool is_digit(char alpha) {
    return alpha >= '0' && alpha <= '9';
}

int digit_to_num(char alpha) {
    return is_digit(alpha) ? alpha - 48 : -1;
}

int main(void) {
    enum {
        DIGITS = 10
    };

    int target_digit_data[DIGITS] = {0};

    char c;
    while ((c = getchar()) != '.') {
        if (is_digit(c))
            target_digit_data[digit_to_num(c)]++;
    }

    print_array(target_digit_data, DIGITS);

    return 0;
}