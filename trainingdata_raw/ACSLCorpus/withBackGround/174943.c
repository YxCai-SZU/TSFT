#include <stdint.h>

/*@
    predicate ans_bound(integer x, integer ans) =
        ans <= 2 * (x / 11) + 2;
*/

/*@
    requires 1 <= x <= 1000000000000000;
    ensures \result <= 2 * (x / 11) + 2;
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t ans;
    uint64_t remainder;

    remainder = x % 11;

    if (remainder > 6)
    {
        ans = 2 * (x / 11) + 2;
    }
    else if (remainder == 0)
    {
        ans = 2 * (x / 11);
    }
    else
    {
        ans = 2 * (x / 11) + 1;
    }

    //@ assert ans <= 2 * (x / 11) + 2;

    return ans;
}
