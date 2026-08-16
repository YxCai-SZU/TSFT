#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;

    logic integer compute_result(integer n) = n * 800 - (n / 15) * 200;

    lemma arithmetic_bounds:
        \forall integer n; is_valid_n(n) ==> n * 800 <= 100 * 800;
    lemma division_bounds:
        \forall integer n; is_valid_n(n) ==> (n / 15) * 200 <= (100 / 15) * 200;
*/

/*@
    requires is_valid_n(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t y;
    int32_t res;

    //@ assert n * 800 <= 100 * 800;
    x = (int32_t)n * 800;

    //@ assert (n / 15) * 200 <= (100 / 15) * 200;
    y = (int32_t)(n / 15) * 200;

    res = x - y;
    //@ assert res == compute_result(n);
    return res;
}
