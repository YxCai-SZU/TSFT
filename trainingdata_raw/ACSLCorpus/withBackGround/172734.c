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
            n - 1 <= 99 && m - 1 <= 99;

    lemma multiplication_bounds:
        \forall integer n, m;
            valid_params(n, m) ==>
            compute_result(n, m) <= 99 * 99;
*/

/*@
    requires valid_params(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    //@ assert n > 1 && m > 1;
    //@ assert n - 1 <= 99 && m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    
    return (n - 1) * (m - 1);
}
