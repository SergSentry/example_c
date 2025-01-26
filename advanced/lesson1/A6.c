/*
 A6 Инверсия старших
*/

#include <stdio.h>
#include <inttypes.h>

int32_t main(void)
{
    uint32_t digit = 0;
    if (scanf("%d", &digit) != 1)
        return 1;

    uint32_t result = digit ^ 0xFF000000;

    printf("%u", result);
    
    return 0;
}
