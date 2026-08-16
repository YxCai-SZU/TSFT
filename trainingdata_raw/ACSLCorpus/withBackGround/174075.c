#include <limits.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n && n <= 20 && 1 <= m && m <= 20;

    logic integer compute_result(integer n, integer m) =
        (1 <= n && n <= 9 && m >= 10) ? n * m : -1;

    lemma multiplication_bounds:
        \forall integer n, m;
            1 <= n && n <= 9 && 10 <= m && m <= 20 ==> n * m <= 180;
*/

/*@
    requires valid_range(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at top of scope
    int result;

    if (1 <= n && n <= 9 && m >= 10)
    {
        //@ assert 1 <= n && n <= 9;
        //@ assert 10 <= m && m <= 20;
        //@ assert n * m <= 180;
        result = n * m;
    }
    else
    {
        result = -1;
    }

    return result;
}
