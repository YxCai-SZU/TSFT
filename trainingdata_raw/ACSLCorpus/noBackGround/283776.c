#include <stdint.h>

/*@
    requires (101 <= (x) && (x) <= 1000000000000000000);
    ensures \result <= (x - 100) / 111;
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t ans;
    //@ assert (101 <= (x) && (x) <= 1000000000000000000);
    ans = (x - 100) / 111;
    //@ assert ans <= (x - 100) / 111;
    return ans;
}
