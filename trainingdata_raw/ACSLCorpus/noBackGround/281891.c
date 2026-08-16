#include <stdint.h>
/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == ((((a)) > ((c)) ? ((a)) - ((c)) : ((c)) - ((a))) + (b) + (d));
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t result;

    if (a > c)
    {
        //@ assert a > c;
        result = a - c + b + d;
    }
    else
    {
        //@ assert a <= c;
        result = c - a + b + d;
    }

    return result;
}
