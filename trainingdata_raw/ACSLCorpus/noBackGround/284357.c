#include <stdint.h>

/*@
    requires (1 <= (a) <= 1000000000 &&
        1 <= (b) <= 1000000000 &&
        1 <= (c) <= 1000000000);
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t max;
    uint32_t ans;

    //@ assert b / a <= c || c <= c;
    //@ assert c - (b / a) >= 0 || c - c >= 0;

    if (b / a < c)
    {
        max = b / a;
    }
    else
    {
        max = c;
    }

    ans = c - max;
    return ans;
}
