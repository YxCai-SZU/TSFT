#include <stdint.h>

/*@
    predicate valid_range(integer n, integer m) =
        2 <= n && n <= 100 &&
        2 <= m && m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma result_bounds:
        \forall integer n, m;
        valid_range(n, m) ==> 1 <= compute_result(n, m) <= 9801;
*/

/*@
    requires valid_range(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    // Variable declarations at scope top
    int64_t ans;

    //@ assert n - 1 >= 1;
    //@ assert m - 1 >= 1;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    ans = (n - 1) * (m - 1);
    return ans;
}
