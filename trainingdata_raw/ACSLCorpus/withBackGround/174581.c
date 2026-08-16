#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        2 <= n && n <= 100 &&
        2 <= m && m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma bounds_lemma:
        \forall integer n, m;
        valid_params(n, m) ==>
        (n - 1) >= 1 && (n - 1) <= 99 &&
        (m - 1) >= 1 && (m - 1) <= 99;

    lemma result_bound_lemma:
        \forall integer n, m;
        valid_params(n, m) ==>
        compute_result(n, m) <= 99 * 99;
*/

/*@
    requires valid_params(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    //@ assert n - 1 >= 1 && n - 1 <= 99;
    //@ assert m - 1 >= 1 && m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    
    int64_t ans;
    ans = (n - 1) * (m - 1);
    
    //@ assert ans == compute_result(n, m);
    return ans;
}
