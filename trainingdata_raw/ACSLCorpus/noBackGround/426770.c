#include <stdint.h>

/*@
    requires (2 <= (x) && (x) <= 100) && (2 <= (y) && (y) <= 100);
    ensures \result == (((x) - 1) * ((y) - 1));
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t y)
{
    // Variable declarations at top of scope
    int64_t ans;

    //@ assert x - 1 >= 1;
    //@ assert y - 1 >= 1;
    //@ assert (x - 1) * (y - 1) >= 0;
    //@ assert (x - 1) * (y - 1) <= 99 * 99;

    ans = (x - 1) * (y - 1);
    return ans;
}
