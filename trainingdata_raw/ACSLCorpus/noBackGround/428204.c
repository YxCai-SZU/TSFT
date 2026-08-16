#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000);
    requires (1 <= (t) <= 1000000000);
    ensures \result >= 0;
    ensures \result <= x;
    assigns \nothing;
*/
int32_t func(int32_t x, int32_t t)
{
    int32_t ans;
    ans = x - t;

    if (ans < 0)
    {
        //@ assert ans < 0;
        return 0;
    }
    else
    {
        //@ assert ans >= 0;
        return ans;
    }
}
