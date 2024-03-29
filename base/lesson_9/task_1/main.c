/* f8.c
 *
 *  В последовательности записаны целые числа от M до N где (M < N, M >= 1) в произвольном порядке,
 *  но одно из чисел пропущено. Определить пропущенное число
 *
 */

#include <stdio.h>

int find_loss_digit(int source[], int source_size) {
    int digit = source[0];
    for (int i = 1; i < source_size; i++) {
        if (digit + 1 != source[i])
            return digit + 1;

        digit = source[i];
    }

    return 0;
}

_Bool more(int a, int b) {
    return a > b;
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

int main(void) {
    enum {
        INPUT_LIMIT = 1000
    };

    int source_data[INPUT_LIMIT] = {0};

    int digit = 0;
    if (scanf("%d", &digit) != 1)
        return 1;

    int len = 0;
    while (digit != 0) {
        source_data[len++] = digit;

        if (scanf("%d", &digit) != 1)
            return 1;

        if (len == INPUT_LIMIT)
            return 1;
    }

    bubble_sort_more(source_data, 0, len - 1);

    int loss_digit = find_loss_digit(source_data, len);

    printf("%d", loss_digit);

    return 0;
}
