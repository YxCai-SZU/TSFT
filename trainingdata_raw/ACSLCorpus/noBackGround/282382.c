#include <limits.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0);
    requires (1 <= (k) <= (a) + (b) + (c));
    ensures \result <= (2 * (a) + (b));
*/
int func(int a, int b, int c, int k)
{
    int sum;
    int rest;

    sum = 0;
    rest = k;

    //@ assert sum == 0 && rest == k;

    if (a <= rest)
    {
        sum += a;
        rest -= a;
        //@ assert sum == a && rest == k - a;
    }
    else
    {
        sum += rest;
        //@ assert sum == k && sum <= a;
        //@ assert sum <= (2 * (a) + (b));
        return sum;
    }

    if (b <= rest)
    {
        rest -= b;
        //@ assert rest == k - a - b;
    }
    else
    {
        //@ assert sum == a && rest == k - a && b > rest;
        //@ assert sum <= (2 * (a) + (b));
        return sum;
    }

    if (c <= rest)
    {
        //@ assert rest >= c;
    }
    else
    {
        sum -= c - rest;
        //@ assert sum == a - (c - (k - a - b));
    }

    //@ assert sum <= (2 * (a) + (b));
    return sum;
}
