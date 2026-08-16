#include <stddef.h>

/*@
    predicate valid_input(integer n, integer m) =
        2 <= n <= 100 && 2 <= m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma bounds_lemma:
        \forall integer n, m;
        valid_input(n, m) ==>
        1 <= n - 1 <= 100 && 1 <= m - 1 <= 100;

    lemma result_bound_lemma:
        \forall integer n, m;
        valid_input(n, m) ==>
        compute_result(n, m) <= 10000;
*/

/*@
    requires valid_input(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    // Variable declarations at top
    size_t ans;

    //@ assert n > 1;
    //@ assert m > 1;
    //@ assert n <= 101;
    //@ assert m <= 101;
    //@ assert n - 1 <= 100;
    //@ assert m - 1 <= 100;
    //@ assert 1 <= n - 1 <= 100;
    //@ assert 1 <= m - 1 <= 100;
    //@ assert (n - 1) * (m - 1) <= 10000;

    ans = (n - 1) * (m - 1);

    //@ assert ans == compute_result(n, m);
    return ans;
}
