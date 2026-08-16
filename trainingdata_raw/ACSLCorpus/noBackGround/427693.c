#include <stdint.h>

/*@
    requires ((x) <= 5 && (y) <= 10);
    ensures \result == x * y;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t ans;

    //@ assert ((x) <= 5 && (y) <= 10);
    //@ assert x * y <= 50;

    ans = x * y;
    return ans;
}
