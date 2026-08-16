#include <stdint.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    uint32_t n;
    uint32_t remained;
    uint32_t a;
    uint32_t b;
    int32_t result;

    n = x / 100;
    remained = x % 100;
    a = remained / 5;
    b = remained % 5;

    //@ assert n <= 1000;
    //@ assert a <= 20;
    //@ assert b <= 4;

    if (n <= a + b)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    return result;
}
