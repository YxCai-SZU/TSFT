#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 1000000000 &&
        1 <= (b) && (b) <= 1000000000 &&
        1 <= (c) && (c) <= 1000000000 &&
        1 <= (k) && (k) <= 1000000000);
    ensures \result >= -k;
    ensures \result <= k;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans = 0;
    int64_t k_remaining = k;

    // Use as many coins as possible from A
    if (k_remaining > a)
    {
        ans += a;
        k_remaining -= a;
    }
    else
    {
        ans += k_remaining;
        k_remaining = 0;
    }

    //@ assert ans >= 0 && ans <= k;

    // Use as many coins as possible from B
    if (k_remaining > b)
    {
        k_remaining -= b;
    }
    else
    {
        k_remaining = 0;
    }

    //@ assert k_remaining >= 0 && k_remaining <= k - ans;

    // Use as many coins as possible from C
    if (k_remaining > c)
    {
        ans -= c;
        k_remaining -= c;
    }
    else
    {
        ans -= k_remaining;
        k_remaining = 0;
    }

    //@ assert ans >= -k && ans <= k;
    return ans;
}
