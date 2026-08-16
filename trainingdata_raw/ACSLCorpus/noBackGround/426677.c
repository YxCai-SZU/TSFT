#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        (k) >= 1 && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= k;
    ensures \result == ((k) >= (a) ?
            ((k) >= (a) + (b) ?
                ((k) >= (a) + (b) + (c) ? (a) - (c) : (a) - ((k) - (a) - (b)))
                : (a))
            : (k));
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans = 0;
    int64_t k_flag = k;

    // Use all the 'a's
    if (k_flag >= a)
    {
        ans += a;
        k_flag -= a;
    }
    else
    {
        ans += k_flag;
        k_flag = 0;
    }

    // Use all the 'b's
    if (k_flag >= b)
    {
        k_flag -= b;
    }
    else
    {
        k_flag = 0;
    }

    // Use all the 'c's and count the number of 'c's
    if (k_flag >= c)
    {
        ans -= c;
    }
    else
    {
        ans -= k_flag;
    }

    //@ assert ans <= k;
    return ans;
}
