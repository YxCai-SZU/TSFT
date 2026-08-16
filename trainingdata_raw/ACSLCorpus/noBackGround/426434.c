#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result <= (((a) * (b)) / 2);
    ensures \result <= c;
    ensures \result == (((a) * (b)) / 2) || \result == c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at scope top
    uint32_t product;
    uint32_t half_product;
    uint32_t result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert a * b <= 10000;

    product = a * b;
    half_product = product / 2;

    if (half_product < c)
    {
        result = half_product;
    }
    else
    {
        result = c;
    }

    //@ assert result <= half_product;
    //@ assert result <= c;
    //@ assert result == half_product || result == c;

    return result;
}
