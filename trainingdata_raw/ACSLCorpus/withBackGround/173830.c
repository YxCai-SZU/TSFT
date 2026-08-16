#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n <= 100 &&
        0 <= a <= n * n;

    logic integer compute_result(integer n, integer a) =
        n * n - a;

    lemma n_squared_bound: \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
*/

/*@
    requires valid_params(n, a);
    ensures \result == compute_result(n, a);
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t a)
{
    // Variable declarations at scope top
    int32_t b;

    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    //@ assert n * n <= 10000;
    //@ assert 0 <= n * n - a;

    b = n * n - a;
    return b;
}
