#include <limits.h>

/*@
    requires (1 <= (n) <= 10000 &&
        1 <= (k) <= 10000 &&
        1 <= (y) < (x) <= 10000);
    ensures \result == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
    assigns \nothing;
*/
long func(long n, long k, long x, long y)
{
    long ans;

    //@ assert 1 <= x && x <= 10000;
    //@ assert 1 <= n && n <= 10000;
    //@ assert n * x <= 100000000;
    //@ assert k * x <= 100000000;
    //@ assert (n - k) * y <= 100000000;

    if (n <= k)
    {
        ans = n * x;
    }
    else
    {
        ans = k * x + (n - k) * y;
    }

    return ans;
}
