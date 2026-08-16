#include <limits.h>

/*@
    requires (1 <= (n) <= 10000 &&
        1 <= (k) <= 10000 &&
        1 <= (y) < (x) <= 10000);
    ensures \result == ((n) <= (k) ? (x) * (n) : (x) * (k) + (y) * ((n) - (k)));
    assigns \nothing;
*/
int func(int n, int k, int x, int y)
{
    // Variable declarations at scope top
    int result;

    if (n <= k)
    {
        //@ assert 1 <= n <= 10000;
        //@ assert 1 <= x <= 10000;
        //@ assert x * n <= 10000 * 10000;
        result = x * n;
    }
    else
    {
        //@ assert 1 <= k <= 10000;
        //@ assert 1 <= x <= 10000;
        //@ assert 1 <= y <= 10000;
        //@ assert x * k + y * (n - k) <= 10000 * 10000 + 9999 * 10000;
        result = x * k + y * (n - k);
    }

    return result;
}
