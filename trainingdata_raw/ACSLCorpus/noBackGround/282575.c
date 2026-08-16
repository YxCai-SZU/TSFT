#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (t) <= 20);
    ensures \result == ((b) * ((t) / (a)));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t t)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert a > 0 && a <= 20;
    //@ assert t > 0 && t <= 20;
    //@ assert b > 0 && b <= 20;
    //@ assert t / a <= 20;
    //@ assert b * (t / a) <= 400;

    result = b * (t / a);
    return result;
}
