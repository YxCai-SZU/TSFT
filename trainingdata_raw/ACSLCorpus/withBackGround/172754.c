#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n <= 100 &&
        0 <= a <= n * n;

    logic integer compute_result(integer n, integer a) =
        n * n - a;

    lemma multiplication_bounds: \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
    lemma subtraction_safe: \forall integer n, a; valid_params(n, a) ==> n * n >= a;
*/

/*@
    requires valid_params(n, a);
    ensures \result == compute_result(n, a);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    //@ assert n * n >= a;
    //@ assert n * n <= 10000;

    result = n * n - a;

    //@ assert result == compute_result(n, a);
    return result;
}
