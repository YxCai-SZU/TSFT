#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        (a) <= 1000000 && (b) <= 1000000 && (c) <= 1000000 &&
        (k) >= 0 && (k) <= 1000000000);
    ensures \result >= -c && \result <= a;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int64_t k)
{
    int32_t ans = 0;
    int64_t remaining_k = k;

    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0 &&         (a) <= 1000000 && (b) <= 1000000 && (c) <= 1000000 &&         (k) >= 0 && (k) <= 1000000000);

    if (remaining_k > (int64_t)a)
    {
        ans += a;
        remaining_k -= (int64_t)a;
        //@ assert ans == a && remaining_k == k - a;
    }
    else
    {
        ans += (int32_t)remaining_k;
        //@ assert ans == k && ans <= a;
        return ans;
    }

    if (remaining_k > (int64_t)b)
    {
        remaining_k -= (int64_t)b;
        //@ assert remaining_k == k - a - b;
    }
    else
    {
        remaining_k = 0;
        //@ assert remaining_k == 0;
    }

    if (remaining_k > (int64_t)c)
    {
        ans -= c;
        remaining_k -= (int64_t)c;
        //@ assert ans == a - c && remaining_k == k - a - b - c;
    }
    else
    {
        ans -= (int32_t)remaining_k;
        //@ assert ans == a - remaining_k && remaining_k <= c;
    }

    //@ assert ans >= -c && ans <= a;
    return ans;
}
