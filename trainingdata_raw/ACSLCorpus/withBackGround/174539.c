#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer func_spec(integer n) = 800 * n - 200 * (n / 15);

    lemma overflow_bound1: \forall integer n; valid_n(n) ==> 800 * n <= 80000;
    lemma overflow_bound2: \forall integer n; valid_n(n) ==> 200 * (n / 15) <= 1400;
    lemma subtraction_safe: \forall integer n; valid_n(n) ==> 800 * n >= 200 * (n / 15);
*/

/*@
    requires valid_n(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
int64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    int64_t result;

    //@ assert 800 * n <= 80000;
    //@ assert 200 * (n / 15) <= 1400;
    //@ assert 800 * n >= 200 * (n / 15);

    result = 800 * (int64_t)n - 200 * (int64_t)(n / 15);
    return result;
}
