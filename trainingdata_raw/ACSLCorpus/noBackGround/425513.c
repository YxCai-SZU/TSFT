#include <limits.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0);
    requires (1 <= (a) + (b) + (c) <= 200000000);
    requires (1 <= (k) <= (a) + (b) + (c));
    ensures ((\result) >= -(k) && (\result) <= (k));
*/
int func(int a, int b, int c, int k)
{
    int result = 0;
    int k_remaining = k;

    //@ assert k_remaining >= 0;

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

    //@ assert result >= 0 && result <= k;

    if (k_remaining > b)
    {
        k_remaining -= b;
    }
    else
    {
        k_remaining = 0;
    }

    //@ assert k_remaining >= 0;

    if (k_remaining > c)
    {
        result -= c;
        k_remaining -= c;
    }
    else
    {
        result -= k_remaining;
        k_remaining = 0;
    }

    //@ assert k_remaining == 0;
    //@ assert ((result) >= -(k) && (result) <= (k));

    return result;
}
