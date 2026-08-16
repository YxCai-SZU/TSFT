#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
    predicate is_even(integer v) = v % 2 == 0;
    logic integer remainder(integer x) = x - (x / 2) * 2;
*/

/*@
    requires valid_range(x) && valid_range(y);
    requires is_even(y);
    ensures \result <= x;
    ensures 0 <= \result;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations at top of scope
    uint32_t ans;

    //@ assert x / 2 <= 50;
    //@ assert (x / 2) * 2 <= 100;

    ans = x - (x / 2) * 2;

    if (y >= 2 && y <= 6)
    {
        if (x >= 1 && x <= 3)
        {
            ans = 0;
        }
        else if (x >= 4 && x <= 7)
        {
            ans = 1;
        }
        else
        {
            ans = x - (x / 2) * 2;
        }
    }

    //@ assert ans <= x;
    //@ assert 0 <= ans;
    return ans;
}
