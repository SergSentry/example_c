/*
 A0 Сколько раз встречается максимум
*/

#include <stdio.h>
#include <inttypes.h>

int32_t main(void)
{
    uint32_t amount_digits = 0;
    if (scanf("%d", &amount_digits) != 1)
        return 1;

    int32_t max = INT32_MIN;
    uint32_t amount_max = 0;
    for (size_t i = 0; i < amount_digits; i++)
    {
        int32_t digit = 0;
        if (scanf("%d", &digit) != 1)
            break;

        if (max < digit)
        {
            max = digit;
            amount_max = 1;
        } else if (max == digit)
        {
            amount_max++;
        }
    }

    printf("%d", amount_max);

    return 0;
}
