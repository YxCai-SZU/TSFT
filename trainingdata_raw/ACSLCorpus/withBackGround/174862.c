#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        0 <= m && m <= n * n;

    logic integer compute_result(integer n, integer m) = n * n - m;

    lemma result_nonnegative:
        \forall integer n, m;
        valid_params(n, m) ==> compute_result(n, m) >= 0;

    lemma n_squared_bound:
        \forall integer n;
        1 <= n && n <= 100 ==> n * n <= 10000;
*/

/*@
    requires valid_params(n, m);
    ensures \result == compute_result(n, m);
    ensures \result >= 0;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int result;

    //@ assert valid_params(n, m);
    //@ assert n * n - m >= 0;
    //@ assert n * n <= 10000;

    result = n * n - m;
    return result;
}
