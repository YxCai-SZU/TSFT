#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m, integer a) =
        1 <= n <= 100 &&
        0 <= m <= n &&
        0 <= a <= n - m;

    logic integer compute_b(integer n, integer m, integer a) = n - m - a;

    lemma arithmetic_bounds:
        \forall integer n, m, a;
        valid_params(n, m, a) ==>
        n >= m &&
        n - m >= a &&
        n - m - a >= 0 &&
        n - m - a <= n;
*/

/*@
    requires valid_params(n, m, a);
    ensures \result == compute_b(n, m, a);
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m, int32_t a)
{
    int32_t b;

    //@ assert n >= m;
    //@ assert n - m >= a;
    //@ assert n - m - a >= 0;
    //@ assert n - m - a <= n;

    b = n - m - a;

    //@ assert b == n - m - a;

    return b;
}
