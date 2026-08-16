#include <stdint.h>


int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t max = 0;

    if (a + b + 1 <= c)
    {
        max = 1 + b;
        uint32_t remaining = c - (a + b + 1);
        max += remaining / 2;
    }
    else if (c >= a + 1)
    {
        max = c;
    }

    //@ assert max <= 200;

    if (max > 100)
    {
        return -1;
    }
    else
    {
        return (int32_t)max;
    }
}
