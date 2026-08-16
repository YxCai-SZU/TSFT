#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 9 &&
        1 <= (b) && (b) <= 9 &&
        1 <= (c) && (c) <= 9);
    ensures \result == a * 10 + b + c ||
            \result == a + b * 10 + c ||
            \result == a + b + c * 10;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t max;
    uint32_t result;

    //@ assert (1 <= (a) && (a) <= 9 &&         1 <= (b) && (b) <= 9 &&         1 <= (c) && (c) <= 9);

    if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
    }
    else
    {
        max = c;
    }

    //@ assert max == (((a) >= (b) && (a) >= (c)) ? (a) :         ((b) >= (a) && (b) >= (c)) ? (b) :         (c));
    //@ assert max == a || max == b || max == c;

    result = max * 10 + (a + b + c - max);

    //@ assert result == a * 10 + b + c || result == a + b * 10 + c || result == a + b + c * 10;

    return result;
}
