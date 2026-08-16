#include <limits.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1 &&
        (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result >= (-(a) - (b) - (c));
    ensures \result <= ((a) + (b) + (c));
*/
int func(int a, int b, int c, int k)
{
    int result = 0;
    int k_remaining = k;

    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1 &&         (k) <= (a) + (b) + (c) && (k) <= 2000000000);

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

    //@ assert result >= (-(a) - (b) - (c)) && result <= ((a) + (b) + (c));

    if (k_remaining > b)
    {
        k_remaining -= b;
    }
    else
    {
        k_remaining = 0;
    }

    //@ assert result >= (-(a) - (b) - (c)) && result <= ((a) + (b) + (c));

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

    //@ assert result >= (-(a) - (b) - (c));
    //@ assert result <= ((a) + (b) + (c));

    return result;
}
