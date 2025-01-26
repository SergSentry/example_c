/*
 A4 Поиск последовательности
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
    uint32_t max = digit & mask;

    for (size_t i = 1; i <= 32 - k; i++)
    {
        mask <<= 1;
        uint32_t tmp = (digit & mask) >> i;

        if (max < tmp)
            max = tmp;
    }

    printf("%u", max);

    return 0;
}
