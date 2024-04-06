/* g3.c
 *
 *  В файле input.txt строка из 1000 символов.
 *  Показать номера символов совпадающих с последним символов строки.
 *
 */

#include <stdio.h>
#include <string.h>

const char *INPUT_FILE = "input.txt\0";
const char *OUTPUT_FILE = "output.txt\0";

int main(void) {
    enum {
        INPUT_LIMIT = 1001
    };

    char line[INPUT_LIMIT] = {0};

    FILE *input_file;
    if ((input_file = fopen(INPUT_FILE, "r")) == NULL) {
        printf("Error, input file can not be open!");
        return 1;
    }

    char c, last_char;
    int count = 0;
    while (((c = getc(input_file)) != EOF) && (c != '\n')) {
        line[count++] = c;
        last_char = c;
    }

    line[count] = '\0';
    fclose(input_file);

    FILE *output_file;
    if ((output_file = fopen(OUTPUT_FILE, "w")) == NULL) {
        printf("Error, output file can not be open!");
        return 1;
    }

    for (int i = 0; i < count - 1; ++i) {
        if (line[i] == last_char)
            fprintf(output_file, "%d ", i);
    }

    fclose(output_file);

    return 0;
}