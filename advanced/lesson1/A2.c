/*
 A2 Циклический сдвиг
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

    uint32_t result = (digit >> k) | (digit << (32 - k));

    printf("%u", result);

    return 0;
}
