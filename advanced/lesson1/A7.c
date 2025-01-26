/*
 A7 Не пара
*/

#include <stdio.h>
#include <inttypes.h>

int32_t main(void)
{
    uint32_t amount_digits = 0;
    if (scanf("%d", &amount_digits) != 1)
        return 1;

    uint32_t result = 0;

    for (size_t i = 0; i < amount_digits; i++)
    {
        uint32_t digit = 0;
        if (scanf("%d", &digit) != 1)
            return 1;
        
        result ^= digit;
    }

    printf("%d", result);
    
    return 0;
}
