#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> (unsigned)\result == a * b;
    ensures \result == -1 ==> (unsigned)(a * b) > 1000000000;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint64_t x;
    int32_t result;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;

    x = (uint64_t)a * (uint64_t)b;

    if (x <= 1000000000UL)
    {
        result = (int32_t)x;
        //@ assert result >= 0;
        //@ assert (unsigned)result == a * b;
    }
    else
    {
        result = -1;
        //@ assert result == -1;
        //@ assert (unsigned)(a * b) > 1000000000;
    }

    return result;
}
