#include <stdint.h>

/*@
    requires (0 <= (a) <= 50) && (0 <= (b) <= 50) && (0 <= (c) <= 50);
    ensures \result <= c;
    ensures \result <= a + b;
    ensures \result == a + b || \result == c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t s;
    uint32_t res;

    s = a + b;
    if (s < c)
    {
        //@ assert s <= a + b;
        res = s;
    }
    else
    {
        //@ assert c <= a + b;
        res = c;
    }
    return res;
}
