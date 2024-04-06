/* g8.c
 *
 *  В файле input.txt дана строка не более 1000 символов, содержащая буквы, цифры и тд
 *  Все числа из строки поместить в отдельный массив
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long file_size(FILE *file) {
    long position = ftell(file);
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, position, SEEK_SET);
    return size;
}

long read_string(const char *file_name, char **buffer) {
    FILE *file = fopen(file_name, "r");
    if (file != NULL) {
        long size = file_size(file);
        char *data = (char *) malloc((size + 1) * sizeof(char));
        fread(data, 1, size, file);
        *buffer = data;
        fclose(file);
        return size;
    }

    return -1;
}

_Bool is_digit(char alpha) {
    return alpha >= '0' && alpha <= '9';
}

_Bool more(int a, int b) {
    return a > b;
}

void bubble_sort_more(int source[], int l, int r) {
    for (int i = l; i < r; ++i) {
        for (int j = r - 1; j > i; --j) {
            if (more(source[i], source[j])) {
                int tmp = source[i];
                source[i] = source[j];
                source[j] = tmp;
            }
        }
    }
}

void make_string(const char *source_data, long source_size, int **buffer, int *buffer_size) {
    int *data = (int *) malloc(source_size * sizeof(int));
    int *data_index = data;
    *buffer_size = 0;

    while (*source_data != '\0') {
        if (is_digit(*source_data)) {
            char *digit = (char *) malloc(65 * sizeof(char));
            memset(digit, 0, 65 * sizeof(char));

            char *digit_index = digit;
            int i = 0;
            while (is_digit(*source_data)) {
                *digit_index++ = *source_data++;
                if (++i == 64)
                    break;
            }
            *digit_index++ = '\0';
            *data_index = atoi(digit);
            *data_index++;
            (*buffer_size)++;

            free(digit);
        }

        *source_data++;
    }

    *buffer = data;
}

long write_digits(const char *file_name, int source[], int source_size) {
    FILE *file = fopen(file_name, "w");
    if (file != NULL) {
        int size = 0;
        for (int i = 0; i < source_size; i++) {
            if (i < source_size - 1)
                size += fprintf(file, "%d ", source[i]);
            else
                size += fprintf(file, "%d", source[i]);
        }

        fclose(file);
        return size;
    }

    return -1;
}

int main(void) {
    const char *INPUT_FILE_NAME = "input.txt\0";
    const char *OUTPUT_FILE_NAME = "output.txt\0";

    char *input_data = NULL;

    long input_data_size = read_string(INPUT_FILE_NAME, &input_data);
    if (input_data_size > 0) {
        int *output_data = NULL;
        int output_count = 0;

        make_string(input_data, input_data_size, &output_data, &output_count);

        bubble_sort_more(output_data, 0, output_count);

        write_digits(OUTPUT_FILE_NAME, output_data, output_count);

        if (output_data != NULL)
            free(output_data);
    }

    if (input_data != NULL)
        free(input_data);

    return 0;
}
