#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        (k) >= 1 && (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) <= 2000000000);
    ensures \result <= a + b + c;
    ensures \result >= k - b - c;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t k_remaining;
    int32_t sum;
    int32_t a_remaining;

    k_remaining = k;
    sum = 0;
    a_remaining = a;

    // Take all of a
    if (k_remaining <= a_remaining)
    {
        sum += k_remaining;
        //@ assert sum <= a + b + c;
        return sum;
    }
    else
    {
        sum += a_remaining;
        k_remaining -= a_remaining;
    }

    // Take all of b
    if (k_remaining <= b)
    {
        //@ assert sum <= a + b + c;
        return sum;
    }
    else
    {
        k_remaining -= b;
    }

    // Take all of c
    if (k_remaining <= c)
    {
        //@ assert sum <= a + b + c;
        return sum;
    }
    else
    {
        k_remaining -= c;
    }

    // Take the rest from a in reverse
    //@ assert sum <= a + b + c;
    //@ assert k_remaining >= 0;
    //@ assert k_remaining <= a + b + c;
    //@ assert sum + k_remaining <= a + b + c;
    sum += k_remaining;
    //@ assert sum <= a + b + c;
    return sum;
}
