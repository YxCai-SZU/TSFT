#include <stdint.h>

/*@
    requires (1 <= (a) && 1 <= (b) && 1 <= (t) &&
        (a) <= 20 && (b) <= 20 && (t) <= 20);
    ensures \result == (((t) / (a)) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t t)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert t / a <= 20;
    //@ assert (t / a) * b <= 400;
    
    result = (t / a) * b;
    return result;
}
