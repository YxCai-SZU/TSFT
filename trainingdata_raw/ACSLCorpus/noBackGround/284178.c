#include <stdint.h>

/*@
    requires (1 <= (a) && 1 <= (b) && 1 <= (t) && (a) <= 20 && (b) <= 20 && (t) <= 20);
    ensures \result == (((t) / (a)) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t t)
{
    // Variable declarations at top of scope
    uint32_t div_result;
    uint32_t result;

    //@ assert 1 <= a && a <= 20;
    //@ assert 1 <= b && b <= 20;
    //@ assert 1 <= t && t <= 20;

    //@ assert t / a <= 20;
    div_result = t / a;

    //@ assert div_result * b <= 400;
    result = div_result * b;

    //@ assert result == (t / a) * b;
    return result;
}
