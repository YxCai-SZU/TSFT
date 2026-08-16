#include <stdint.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) && 1 <= (k) && (k) <= (a) + (b) + (c));
    ensures \result >= -c;
    ensures \result <= a;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t k_remaining;
    int32_t res;

    k_remaining = k;
    res = 0;

    if (a < k_remaining)
    {
        res += a;
        k_remaining -= a;
    }
    else
    {
        //@ assert k_remaining == k;
        //@ assert res == 0;
        //@ assert k <= a;
        //@ assert k >= -c;
        //@ assert k <= a;
        return k;
    }

    if (b < k_remaining)
    {
        k_remaining -= b;
    }
    else
    {
        //@ assert k_remaining <= b;
        //@ assert res == a;
        //@ assert res >= -c;
        //@ assert res <= a;
        return res;
    }

    res -= k_remaining;

    //@ assert res >= -c;
    //@ assert res <= a;

    return res;
}
