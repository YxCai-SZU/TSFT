#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b;
    ensures \result >= c * d;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    uint64_t result;

    //@ assert a <= 10000;
    //@ assert b <= 10000;
    //@ assert c <= 10000;
    //@ assert d <= 10000;

    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;

    if (a * b > c * d)
    {
        result = a * b;
    }
    else
    {
        result = c * d;
    }

    return result;
}
