#include <limits.h>

/*@
    requires ((((a)) >= 0) && (((b)) >= 0) && (((c)) >= 0) &&
        (k) >= 1 && (k) <= (a) + (b) + (c) && (a) + (b) + (c) <= 2000000000);
    ensures \result <= ((a) + (b) + (c));
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int k_remaining;
    int res;

    k_remaining = k;
    res = 0;

    if (a >= k_remaining)
    {
        res += k_remaining;
        //@ assert res <= ((a) + (b) + (c));
        return res;
    }
    else
    {
        res += a;
        k_remaining -= a;
    }

    if (b >= k_remaining)
    {
        //@ assert res <= ((a) + (b) + (c));
        return res;
    }
    else
    {
        k_remaining -= b;
        res += k_remaining;
    }

    //@ assert res <= ((a) + (b) + (c));
    return res;
}
