/* g4.c
 *
 *  В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом
 *  Найти только те символы слов которые встречаются в обоихсловах только один раз
 *
 */

#include <stdio.h>
#include <string.h>

const char *INPUT_FILE = "input.txt\0";
const char *OUTPUT_FILE = "output.txt\0";

void sort(char str[]) {
    char temp;
    size_t size = strlen(str);
    for (int i = 0; i < size; ++i) {
        for (size_t j = size - 1; j > i; --j) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int is_char_exists(int size, const char buffer[], char c) {
    for (int i = 0; i < size; ++i) {
        if (buffer[i] == c)
            return 1;
    }
    return 0;
}

void process(char in[], char out[]) {
    size_t in_len = strlen(in);
    int out_len = 0;

    int space_index = -1;
    for (int i = 0; i < in_len; ++i) {
        if (in[i] == ' ') {
            space_index = i;
            break;
        }
    }

    int count1, count2;
    for (int i = 0; i < in_len; ++i) {
        count1 = 0;
        count2 = 0;
        for (int j = 0; j < space_index; ++j) {
            if (in[j] == in[i])
                count1++;
        }

        for (int j = space_index + 1; j < in_len; ++j) {
            if (in[j] == in[i])
                count2++;
        }

        if (count1 == 1 && count2 == 1 && is_char_exists(out_len, out, in[i]) != 1)
            out[out_len++] = in[i];
    }
    out[out_len] = '\0';

    sort(out);
}

int main(void) {
    enum {
        INPUT_LIMIT = 101
    };

    FILE *input_file;
    char line[INPUT_LIMIT * 2] = {0}, result[INPUT_LIMIT] = {0};

    if ((input_file = fopen(INPUT_FILE, "r")) == NULL) {
        printf("Error, input file can not be open!");
        return 1;
    }
    fscanf(input_file, "%[^\n]", line);
    fclose(input_file);

    process(line, result);

    FILE *output_file;
    if ((output_file = fopen(OUTPUT_FILE, "w")) == NULL) {
        printf("Error, output file can not be open!");
        return 1;
    }

    for (int i = 0; i < strlen(result); ++i)
        fprintf(output_file, "%c ", result[i]);

    fclose(output_file);

    return 0;
}