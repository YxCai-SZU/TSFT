#include <limits.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n <= 100 &&
        0 <= a <= n * n;

    logic integer compute_result(integer n, integer a) =
        n * n - a;

    lemma bounds_lemma:
        \forall integer n, a;
            valid_params(n, a) ==> n * n >= 0;

    lemma result_nonnegative:
        \forall integer n, a;
            valid_params(n, a) ==> compute_result(n, a) >= 0;
*/

/*@
    requires valid_params(n, a);
    ensures \result == compute_result(n, a);
    assigns \nothing;
*/
int func(int n, int a)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;
    //@ assert n * n >= 0;
    //@ assert n * n <= 10000;
    //@ assert n * n - a >= 0;

    result = n * n - a;
    return result;
}
