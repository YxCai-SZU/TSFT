#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 1000000000 &&
        1 <= (b) && (b) <= 1000000000 &&
        1 <= (c) && (c) <= 1000000000 &&
        1 <= (k) && (k) <= 1000000000 &&
        (a) + (b) + (c) >= (k));
    ensures \result >= -c;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int sum = 0;
    int remaining_k = k;

    //@ assert (1 <= (a) && (a) <= 1000000000 &&         1 <= (b) && (b) <= 1000000000 &&         1 <= (c) && (c) <= 1000000000 &&         1 <= (k) && (k) <= 1000000000 &&         (a) + (b) + (c) >= (k));

    if (remaining_k >= a)
    {
        sum += a;
        remaining_k -= a;
    }
    else
    {
        sum += remaining_k;
        remaining_k = 0;
    }

    //@ assert sum >= 0 && sum <= a;

    if (remaining_k >= b)
    {
        remaining_k -= b;
    }
    else
    {
        remaining_k = 0;
    }

    //@ assert remaining_k >= 0;

    if (remaining_k >= c)
    {
        sum -= c;
        remaining_k -= c;
    }
    else
    {
        sum -= remaining_k;
        remaining_k = 0;
    }

    //@ assert sum >= -c;
    //@ assert sum <= a;

    return sum;
}
