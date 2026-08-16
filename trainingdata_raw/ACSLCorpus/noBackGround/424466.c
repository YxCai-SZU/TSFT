#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        (k) >= 1 && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= k;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t k_remaining;
    int64_t sum;
    int64_t a_remaining;
    int64_t b_remaining;
    int64_t c_remaining;

    k_remaining = k;
    sum = 0;
    a_remaining = a;
    b_remaining = b;
    c_remaining = c;

    //@ assert ((a_remaining) >= 0 && (b_remaining) >= 0 && (c_remaining) >= 0 &&         (k_remaining) >= 1 && (k_remaining) <= (a_remaining) + (b_remaining) + (c_remaining) && (k_remaining) <= 2000000000);
    //@ assert sum == 0 && k_remaining == k;

    if (k_remaining > a_remaining)
    {
        sum += a_remaining;
        k_remaining -= a_remaining;
        a_remaining = 0;
    }
    else
    {
        a_remaining -= k_remaining;
        sum += k_remaining;
        k_remaining = 0;
    }

    //@ assert sum <= a;
    //@ assert k_remaining >= 0 && k_remaining <= k - sum;

    if (k_remaining > b_remaining)
    {
        k_remaining -= b_remaining;
        b_remaining = 0;
    }
    else
    {
        b_remaining -= k_remaining;
        k_remaining = 0;
    }

    //@ assert k_remaining >= 0 && k_remaining <= k - sum;

    if (k_remaining > c_remaining)
    {
        sum -= c_remaining;
        k_remaining -= c_remaining;
        c_remaining = 0;
    }
    else
    {
        c_remaining -= k_remaining;
        sum -= k_remaining;
        k_remaining = 0;
    }

    //@ assert sum == ((k) <= (a) ? (k) : ((k) <= (a) + (b) ? (a) : (a) - ((k) - (a) - (b))));
    //@ assert sum <= k;

    return sum;
}
