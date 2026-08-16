#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        2 <= n <= 100 && 2 <= m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma arithmetic_bounds:
        \forall integer n, m;
        valid_range(n, m) ==> 
        (n - 1) <= 99 && (m - 1) <= 99 && compute_result(n, m) <= 9801;
*/

/*@
    requires valid_range(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int result;

    //@ assert n > 1 && m > 1;
    //@ assert (n - 1) <= 99 && (m - 1) <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    result = (n - 1) * (m - 1);
    return result;
}
