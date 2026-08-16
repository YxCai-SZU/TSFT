#include <stdint.h>

/*@
    predicate ans_in_range(integer x, integer ans) =
        ans >= 0 && ans <= (x / 11) * 2 + 2;
*/

/*@
    requires 1 <= x && x <= 100000000000000000;
    ensures \result >= 0;
    ensures \result <= (x / 11) * 2 + 2;
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t ans;
    ans = (x / 11) * 2;

    //@ assert ans >= 0;
    //@ assert ans <= (x / 11) * 2 + 2;

    if (x % 11 == 0)
    {
        //@ assert ans >= 0;
        //@ assert ans <= (x / 11) * 2 + 2;
    }
    else if (x % 11 == 1 || x % 11 == 2 || x % 11 == 3 || x % 11 == 4 ||
             x % 11 == 5 || x % 11 == 6 || x % 11 == 7 || x % 11 == 8 ||
             x % 11 == 9 || x % 11 == 10)
    {
        ans += 1;
        //@ assert ans >= 0;
        //@ assert ans <= (x / 11) * 2 + 2;
    }
    else
    {
        //@ assert ans >= 0;
        //@ assert ans <= (x / 11) * 2 + 2;
    }

    //@ assert ans_in_range(x, ans);
    return ans;
}
