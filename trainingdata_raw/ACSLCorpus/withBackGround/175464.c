#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer compute_result(integer n) = n * 800 - (n / 15) * 200;

    lemma n_bound_1: \forall integer n; valid_n(n) ==> n * 800 <= 100 * 800;
    lemma n_bound_2: \forall integer n; valid_n(n) ==> n / 15 <= 6;
    lemma n_bound_3: \forall integer n; valid_n(n) ==> (n / 15) * 200 <= 6 * 200;
*/

/*@
    requires valid_n(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result;

    //@ assert valid_n(n);
    //@ assert n * 800 <= 100 * 800;
    //@ assert n / 15 <= 6;
    //@ assert (n / 15) * 200 <= 6 * 200;

    result = (int32_t)(n * 800 - (n / 15) * 200);
    
    //@ assert result == compute_result(n);
    
    return result;
}
