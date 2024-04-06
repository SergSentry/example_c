/* g5.c
 *
 *  В файле input.txt дана строка не более 100 символов
 *  Найти заменить 'a' на 'b' и наоборот, как заглавные так и строчные
 *
 */

#include <stdio.h>
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

long write_string(const char *file_name, char **buffer) {
    FILE *file = fopen(file_name, "w");
    if (file != NULL) {
        int size = fprintf(file, "%s", *buffer);
        fclose(file);
        return size;
    }

    return -1;
}

void make_string(const char *source_data, long source_size, char **buffer) {
    char *data = (char *) malloc((source_size) * sizeof(char));
    int i = 0;
    for (; i < source_size; i++) {
        switch (source_data[i]) {
            case 'a':
                data[i] = 'b';
                break;
            case 'A':
                data[i] = 'B';
                break;
            case 'b':
                data[i] = 'a';
                break;
            case 'B':
                data[i] = 'A';
                break;
            default:
                data[i] = source_data[i];
                break;
        }
    }

    data[i] = '\0';
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
