#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000 &&
        1 <= (m) <= 1000 &&
        0 <= (k) <= (n) * (m));
    ensures \result == (n * m - k >= 0);
    assigns \nothing;
*/
bool func(int n, int m, int k)
{
    // Variable declarations at top
    int product;
    bool result;

    //@ assert 1 <= n && n <= 1000;
    //@ assert 1 <= m && m <= 1000;
    //@ assert n * m <= 1000 * 1000;

    product = n * m;
    result = (product - k >= 0);
    return result;
}
