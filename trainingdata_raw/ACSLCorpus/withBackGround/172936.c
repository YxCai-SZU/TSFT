#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        2 <= n && n <= 100 &&
        2 <= m && m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);
*/

/*@
    requires valid_range(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int func(int n, int m)
{
    int ans;
    //@ assert n > 1 && m > 1;
    //@ assert n <= 100 && m <= 100;
    //@ assert (n - 1) >= 1 && (m - 1) >= 1;
    //@ assert (n - 1) <= 99 && (m - 1) <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    ans = (n - 1) * (m - 1);
    return ans;
}
