/*
 A1 Шифр Цезаря
*/

#include <stdio.h>
#include <inttypes.h>

const uint8_t ALPHA_COUNT = 26;

uint8_t is_lower(char alpha) {
    return (alpha >= 'a' && alpha <= 'z');
}

uint8_t is_upper(char alpha) {
    return (alpha >= 'A' && alpha <= 'Z');
}

uint8_t is_alpha(char alpha) {
    return is_lower(alpha) || is_upper(alpha);
}

uint8_t is_space(char alpha) {
    return alpha == ' ';
}


int32_t main(void) {
    uint32_t key = 0;
    if (scanf("%d", &key) != 1)
        return 1;

    //while (key > ALPHA_COUNT)
    //    key /= ALPHA_COUNT;

    char c;
    while ((c = getchar()) != '.') {
        if (is_space(c)) {
            printf("%c", c);
            continue;
        }

        if (is_alpha(c)) {
            char output_char = '.';

            if (is_lower(c))
                output_char = (char) ((uint8_t) 'a' + (((uint8_t) c - (uint8_t) 'a' + key) % ALPHA_COUNT));
            else if (is_upper(c))
                output_char = (char) ((uint8_t) 'A' + (((uint8_t) c - (uint8_t) 'A' + key) % ALPHA_COUNT));

            printf("%c", output_char);
        }
    }
    putchar('.');

    return 0;
}
