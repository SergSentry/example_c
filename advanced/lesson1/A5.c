/*
 A5 Подсчет битов
*/

#include <stdio.h>
#include <inttypes.h>

int32_t main(void)
{
    uint32_t digit = 0;
    if (scanf("%d", &digit) != 1)
        return 1;

    uint32_t result = digit;
    result = ((result >> 1) & 0x55555555) + (result & 0x55555555);
    result = ((result >> 2) & 0x33333333) + (result & 0x33333333);
    result = ((result >> 4) & 0x0F0F0F0F) + (result & 0x0F0F0F0F);
    result = ((result >> 8) & 0x00FF00FF) + (result & 0x00FF00FF);
    result = ((result >> 16) & 0x0000FFFF) + (result & 0x0000FFFF);

    printf("%u", result);

    return 0;
}
