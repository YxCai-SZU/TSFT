#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t a_minus_one;
    uint32_t b_minus_one;
    uint32_t result;

    //@ assert a > 1;
    a_minus_one = a - 1;

    //@ assert b > 1;
    b_minus_one = b - 1;

    //@ assert a_minus_one <= 99 && b_minus_one <= 99;
    result = a_minus_one * b_minus_one;

    //@ assert result == (((a) - 1) * ((b) - 1));
    return result;
}
