/* g9.c
 *
 *  В файле input.txt строка из маленьких и больших букв, знаков припинания и пробелов.
 *  Удалить из строки все повторяющиеся символы и пробелы
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

_Bool is_space(char alpha) {
    return alpha == ' ';
}

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

long write_string(const char *file_name, char **buffer) {
    FILE *file = fopen(file_name, "w");
    if (file != NULL) {
        int size = fprintf(file, "%s", *buffer);
        fclose(file);
        return size;
    }

    return -1;
}

int frequency_simbol(const char *source, char simbol, int l, int r) {
    int count = 0;
    l = l > r ? r : l;
    for (int i = l; i < r; i++) {
        if (source[i] == simbol)
            count++;
    }

    return count;
}

void make_string(const char *source_data, long source_size, char **buffer) {
    char *data = (char *) malloc(source_size * sizeof(char));
    memset(data, 0, source_size * sizeof(char));

    char *data_index = data;
    int data_len = 0;

    while (*source_data != '\0') {
        if (is_space(*source_data)) {
            *source_data++;
            continue;
        }

        int freq = frequency_simbol(data, *source_data, 0, data_len);
        if (freq == 0) {
            *data_index++ = *source_data;
            data_len++;
        }

        *source_data++;
    }

    *buffer = data;
}

int main(void) {
    const char *INPUT_FILE_NAME = "input.txt\0";
    const char *OUTPUT_FILE_NAME = "output.txt\0";

    char *input_data = NULL;

    long input_data_size = read_string(INPUT_FILE_NAME, &input_data);
    if (input_data_size > 0) {
        char *output_data = NULL;
        make_string(input_data, input_data_size, &output_data);

        write_string(OUTPUT_FILE_NAME, &output_data);

        if (output_data != NULL)
            free(output_data);
    }

    if (input_data != NULL)
        free(input_data);

    return 0;
}
