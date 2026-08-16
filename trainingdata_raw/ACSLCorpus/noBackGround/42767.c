#include <limits.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b;
    ensures \result >= c * d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int sa;
    int sc;
    int ans;

    //@ assert (1 <= (a) <= 10000 && 1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000 && 1 <= (d) <= 10000);
    //@ assert ((a) * (b)) <= 10000 * 10000;
    //@ assert ((c) * (d)) <= 10000 * 10000;

    sa = a * b;
    sc = c * d;

    if (sa > sc)
    {
        ans = sa;
    }
    else
    {
        ans = sc;
    }

    //@ assert ans == sa || ans == sc;
    //@ assert ans >= sa;
    //@ assert ans >= sc;

    return ans;
}
