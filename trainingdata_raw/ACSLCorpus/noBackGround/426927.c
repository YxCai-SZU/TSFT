#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20 && 1 <= (t) <= 20);
    ensures \result == ((b) * ((t) / (a)));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t t)
{
    uint32_t ans;
    uint32_t tmp;

    //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20 && 1 <= (t) <= 20);
    //@ assert ((t) / (a)) <= 20;
    tmp = t / a;

    //@ assert ((b) * ((t) / (a))) <= 400;
    ans = b * tmp;

    //@ assert ans == ((b) * ((t) / (a)));
    return ans;
}
