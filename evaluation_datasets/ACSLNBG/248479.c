#include <stdint.h>


uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert (2 <= (a) && (a) <= 100 &&         2 <= (b) && (b) <= 100);
    //@ assert 1 <= a - 1 && a - 1 <= 99;
    //@ assert 1 <= b - 1 && b - 1 <= 99;
    //@ assert (a - 1) * (b - 1) <= 9801;

    result = (a - 1) * (b - 1);
    //@ assert result == (((a) - 1) * ((b) - 1));
    return result;
}
