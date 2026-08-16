#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == (((x) / 500 * 1000) + (((x) % 500) / 5 * 5));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t ans;
    uint32_t xx;

    ans = 0;
    ans += (x / 500) * 1000;
    xx = x % 500;

    //@ assert (xx / 5) * 5 <= 1000;

    ans += (xx / 5) * 5;
    return ans;
}
