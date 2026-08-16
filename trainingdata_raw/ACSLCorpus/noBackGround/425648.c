#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures ((\result) >= 0 && (\result) <= (a) && ((\result) == (((a)) - ((b)) * 2) || (\result) == 0));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t ans;
    int64_t res;

    ans = a - b * 2;

    if (ans > 0)
    {
        //@ assert ans >= 0;
        res = ans;
    }
    else
    {
        //@ assert ans <= a;
        res = 0;
    }

    return res;
}
