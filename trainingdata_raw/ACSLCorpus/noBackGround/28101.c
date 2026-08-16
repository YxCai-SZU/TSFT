#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 179);
    ensures \result == (360 - ((x) * 2));
    ensures \result <= 360;
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t ans;
    //@ assert x * 2 <= 360;
    ans = 360 - (x * 2);
    //@ assert ans <= 360;
    //@ assert ans == 360 - (x * 2);
    return ans;
}
