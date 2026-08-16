#include <limits.h>

/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    ensures \result == a * c || \result == a * d || \result == b * c ||
            \result == b * d || \result == c * a || \result == c * b ||
            \result == d * a || \result == d * b;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long x;
    long y;
    long ans;

    //@ assert (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    //@ assert -100000000 <= a * c <= 100000000;
    //@ assert -100000000 <= a * d <= 100000000;
    //@ assert -100000000 <= b * c <= 100000000;
    //@ assert -100000000 <= b * d <= 100000000;
    //@ assert -100000000 <= c * a <= 100000000;
    //@ assert -100000000 <= c * b <= 100000000;
    //@ assert -100000000 <= d * a <= 100000000;
    //@ assert -100000000 <= d * b <= 100000000;

    if (a * c > a * d)
    {
        x = a * c;
    }
    else
    {
        x = a * d;
    }

    if (b * c > b * d)
    {
        y = b * c;
    }
    else
    {
        y = b * d;
    }

    if (x > y)
    {
        ans = x;
    }
    else
    {
        ans = y;
    }

    //@ assert ans == a * c || ans == a * d || ans == b * c || ans == b * d || ans == c * a || ans == c * b || ans == d * a || ans == d * b;
    return ans;
}
