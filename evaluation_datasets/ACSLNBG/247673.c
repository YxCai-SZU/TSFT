#include <stdint.h>


uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t x;
    uint32_t result;

    x = a + b;

    //@ assert x == a + b;

    if (x < 24)
    {
        result = x;
    }
    else
    {
        result = x - 24;
    }

    //@ assert result == (x < 24 ? x : x - 24);
    //@ assert result == (((a) + (b)) % 24);

    return result;
}
