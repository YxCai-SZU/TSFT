#include <limits.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma result_bounds:
        \forall integer n, m;
        valid_range(n, m) ==> 0 <= compute_result(n, m) <= 9801;
*/

/*@
    requires valid_range(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int func(int n, int m) {
    // Variable declarations at top of scope
    int result;

    //@ assert n > 0 && n <= 100;
    //@ assert m > 0 && m <= 100;
    //@ assert n - 1 >= 0;
    //@ assert m - 1 >= 0;
    //@ assert (n - 1) * (m - 1) <= 9801;

    result = (n - 1) * (m - 1);
    return result;
}
