#include <stdint.h>


int32_t func(uint32_t x)
{
    int32_t ans;
    uint32_t temp_x;
    uint32_t temp;

    ans = 0;
    temp_x = x;
    temp = x / 500;
    ans += (int32_t)temp * 1000;
    temp_x = x % 500;
    temp = temp_x / 5;
    ans += (int32_t)temp * 5;

    //@ assert ans == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);

    return ans;
}
