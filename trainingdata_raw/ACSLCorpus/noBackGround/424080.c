#include <stdint.h>

/*@
    requires (1 <= (a) <= 1000000000000000000 &&
        1 <= (b) <= 1000000000000000000 &&
        1 <= (c) <= 1000000000000000000 &&
        1 <= (k) <= 1000000000000000000 &&
        (a) + (b) + (c) >= (k));
    ensures ((\result) >= -(k) && (\result) <= (k) && (\result) <= (a + b + c));
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t k_remaining;
    int64_t sum;

    k_remaining = k;
    sum = 0;

    if (a < k_remaining)
    {
        sum += a;
        k_remaining -= a;
    }
    else
    {
        sum = k_remaining;
        k_remaining = 0;
    }

    if (b < k_remaining)
    {
        k_remaining -= b;
    }
    else
    {
        k_remaining = 0;
    }

    if (c < k_remaining)
    {
        sum -= c;
        k_remaining -= c;
    }

    //@ assert sum >= -k && sum <= k;

    return sum;
}
