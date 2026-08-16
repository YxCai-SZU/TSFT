#include <stdint.h>
/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (((b) / (a)) < c ? ((b) / (a)) : c);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t quotient;
    uint32_t ans;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert ((b) / (a)) <= 100;
    //@ assert c <= 100;

    quotient = b / a;
    if (quotient < c) {
        ans = quotient;
    } else {
        ans = c;
    }
    return ans;
}
