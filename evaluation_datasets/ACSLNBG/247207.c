#include <stdint.h>


uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    
    //@ assert a * b <= 100;
    //@ assert a * b * c <= 1000;

    result = a * b * c;
    //@ assert result == ((a) * (b) * (c));
    return result;
}
