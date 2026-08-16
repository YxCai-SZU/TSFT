#include <limits.h>

/*@
    requires (0 <= (a) <= 1000000000 &&
        0 <= (b) <= 1000000000 &&
        0 <= (c) <= 1000000000 &&
        1 <= (k) <= 1000000000 &&
        (a) + (b) + (c) >= (k));
    ensures (-(k) <= (\result) <= (k));
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int k_remaining;
    int result;

    k_remaining = k;
    result = 0;

    // Use all the positive numbers first
    if (k_remaining > a)
    {
        result += a;
        k_remaining -= a;
    }
    else
    {
        result += k_remaining;
        k_remaining = 0;
    }

    // Now use the negative numbers
    if (k_remaining > b)
    {
        k_remaining -= b;
    }
    else
    {
        k_remaining = 0;
    }

    // If there are still Ks left, use the positive numbers again
    if (k_remaining > c)
    {
        result -= c;
    }
    else
    {
        result -= k_remaining;
    }

    //@ assert (-(k) <= (result) <= (k));
    return result;
}
