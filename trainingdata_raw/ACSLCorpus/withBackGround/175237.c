#include <stdbool.h>

/*@
    predicate product_in_range(integer n, integer m) =
        0 <= n <= 1000000000 &&
        0 <= m <= 1000000000 &&
        n * m <= 1000000000 * 1000000000;
*/

/*@
    requires 0 <= n <= 1000000000;
    requires 0 <= m <= 1000000000;
    requires 0 <= k <= 1000000000;
    ensures \result == true <==> n * m - k >= 0;
    assigns \nothing;
*/
bool func(long long n, long long m, long long k)
{
    //@ assert product_in_range(n, m);
    
    if (n * m - k >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
