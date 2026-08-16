#include <stdint.h>

/*@
    requires (0 <= (a) <= 1000000000 &&
        0 <= (b) <= 1000000000 &&
        0 <= (c) <= 1000000000 &&
        1 <= (k) <= 1000000000);
    ensures (-1000000000 <= (\result) <= 1000000000);
    ensures \result <= a;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t r;
    int32_t ans;

    r = k;
    ans = 0;

    //@ assert (0 <= (a) <= 1000000000 &&         0 <= (b) <= 1000000000 &&         0 <= (c) <= 1000000000 &&         1 <= (k) <= 1000000000);
    //@ assert r == k && ans == 0;

    if (a >= r)
    {
        ans += r;
        //@ assert ans == r;
        //@ assert ans <= a;
        return ans;
    }
    else
    {
        r -= a;
        ans += a;
        //@ assert ans == a;
        //@ assert r == k - a;
    }

    //@ assert ans == a && r == k - a;

    if (b >= r)
    {
        //@ assert ans <= a;
        return ans;
    }
    else
    {
        r -= b;
        //@ assert r == k - a - b;
    }

    //@ assert r == k - a - b;

    ans -= r;
    //@ assert ans == a - (k - a - b);

    //@ assert ans >= -1000000000 && ans <= 1000000000;
    //@ assert r <= 1000000000;
    //@ assert ans <= a;

    return ans;
}
