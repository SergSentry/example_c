/*
 A3 Извлечение бит
*/

#include <stdio.h>
#include <inttypes.h>

int32_t main(void)
{
    uint32_t digit = 0;
    if (scanf("%d", &digit) != 1)
        return 1;
    
    uint32_t k = 0;
    if (scanf("%d", &k) != 1)
        return 1;

    if (0 == k || k > 31)
        return 1;

    uint32_t mask = 0xFFFFFFFF >> (32 - k);
    uint32_t result = digit & mask;

    printf("%u", result);

    return 0;
}
