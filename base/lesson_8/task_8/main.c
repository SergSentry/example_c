/* e16.c
 *
 *  Считать массив из 10 элементов.
 *  Определить, какое число в массиве встречается чаще всего
 *
 */

#include <stdio.h>

int frequency_digit(int source[], int digit, int source_size) {
    int count = 0;
    for (int i = 0; i < source_size; i++) {
        if (source[i] == digit)
            count++;
    }

    return count;
}

int max_frequency_digit(int source[], int source_size) {
    int max_freq_digit = source[0];
    int max_freq = 1;

    for (int i = 0; i < source_size; i++) {
        int freq = frequency_digit(source, source[i], source_size);
        if (freq > max_freq) {
            max_freq_digit = source[i];
            max_freq = freq;
        }
    }

    return max_freq_digit;
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

    int digit = max_frequency_digit(source_data, INPUT_LIMIT);

    printf("%d", digit);

    return 0;
}
