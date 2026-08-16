#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d || \result == c + d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t result;

    //@ assert (1 <= (a) <= 10000) && (1 <= (c) <= 10000);
    //@ assert a + c <= 20000;

    //@ assert (1 <= (a) <= 10000) && (1 <= (d) <= 10000);
    //@ assert a + d <= 20000;

    //@ assert (1 <= (b) <= 10000) && (1 <= (c) <= 10000);
    //@ assert b + c <= 20000;

    //@ assert (1 <= (b) <= 10000) && (1 <= (d) <= 10000);
    //@ assert b + d <= 20000;

    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert c + d <= 20000;

    if (a + b < c)
    {
        result = a + c;
    }
    else if (a + b < d)
    {
        result = a + d;
    }
    else if (b + c < d)
    {
        result = b + d;
    }
    else
    {
        result = c + d;
    }

    return result;
}
