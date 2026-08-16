#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 20 &&
        1 <= (b) && (b) <= 20 &&
        1 <= (t) && (t) <= 20);
    ensures \result == (((t) / (a)) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t t)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert 1 <= a && a <= 20;
    //@ assert 1 <= b && b <= 20;
    //@ assert 1 <= t && t <= 20;

    //@ assert t / a <= 20;
    //@ assert (t / a) * b <= 400;

    ans = t / a * b;
    
    //@ assert ans == (((t) / (a)) * (b));
    return ans;
}
