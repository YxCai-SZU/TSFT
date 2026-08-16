#include <stdint.h>
/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1 && \result <= 100000000;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert a * b <= 100000000;
    //@ assert c * d <= 100000000;
    //@ assert a * b >= 1 && c * d >= 1;

    if (a * b > c * d) {
        result = a * b;
    } else {
        result = c * d;
    }

    //@ assert result == a * b || result == c * d;
    return result;
}
