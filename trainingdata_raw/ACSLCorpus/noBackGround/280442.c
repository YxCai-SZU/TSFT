#include <stdbool.h>

/*@
    requires 1 <= n && n <= 100000;
    requires 1 <= m && m <= 100000;
    requires 0 <= k && k <= n * m;
    ensures \result == ((n * m - 1) <= k);
*/
bool func(int n, int m, int k)
{
    // Variable declarations at scope top
    long product;
    bool result;

    //@ assert (1 <= (n) && (n) <= 100000 &&         1 <= (m) && (m) <= 100000 &&         (n) * (m) <= 100000 * 100000);
    product = (long)n * (long)m;

    if (product - 1 <= k)
    {
        //@ assert product - 1 <= k;
        result = true;
    }
    else
    {
        //@ assert !(product - 1 <= k);
        result = false;
    }

    return result;
}
