#include <limits.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n && n <= 100 &&
        0 <= a && a <= n * n;

    logic integer compute_result(integer n, integer a) =
        n * n - a;
*/

/*@
    requires valid_params(n, a);
    ensures \result == compute_result(n, a);
    assigns \nothing;
*/
int func(int n, int a)
{
    // Variable declarations at top of scope
    int b;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;
    //@ assert n * n <= 100 * 100;

    b = n * n - a;
    return b;
}
