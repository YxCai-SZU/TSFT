#include <stdint.h>

/*@
    predicate valid_params(integer n, integer r) =
        1 <= n && n <= 100 &&
        0 <= r && r <= 4111;

    logic integer compute_result(integer n, integer r) =
        (100 - n) * 100 + r;

    lemma no_underflow:
        \forall integer n, r;
        valid_params(n, r) ==>
        100 - n >= 0 &&
        (100 - n) * 100 >= 0 &&
        (100 - n) * 100 + r >= 0;
*/

/*@
    requires valid_params(n, r);
    ensures \result == compute_result(n, r);
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t r)
{
    //@ assert 100 - n >= 0;
    //@ assert (100 - n) * 100 >= 0;
    //@ assert (100 - n) * 100 + r >= 0;
    
    return (100 - n) * 100 + r;
}
