#include <stddef.h>

/*@
    predicate valid_n(integer n) = 1 <= n <= 10000;

    logic integer compute_result(integer n) =
        (n / 500) * 1000 + ((n % 500) / 5) * 5;

    lemma result_formula: \forall integer n; valid_n(n) ==>
        compute_result(n) == (n / 500) * 1000 + ((n % 500) / 5) * 5;
*/

/*@
    requires valid_n(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t c500;
    size_t r500;
    size_t c5;
    size_t r5;
    size_t result;

    c500 = n / 500;
    r500 = n % 500;
    c5 = r500 / 5;
    r5 = r500 % 5;
    result = c500 * 1000 + c5 * 5;

    //@ assert result == compute_result(n);
    return result;
}
