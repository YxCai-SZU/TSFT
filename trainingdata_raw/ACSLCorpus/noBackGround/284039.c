#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result <= c;
    ensures \result == c || \result == c - 1;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t min_ab;
    uint32_t result;

    min_ab = a;
    //@ assert min_ab == a;
    if (b < min_ab)
    {
        min_ab = b;
    }

    result = min_ab;
    if (c < min_ab)
    {
        result = c;
    }

    //@ assert c - 1 <= c;
    if (c - 1 >= min_ab)
    {
        result = c - 1;
    }

    //@ assert result <= c;
    //@ assert result == c || result == c - 1;
    return result;
}
