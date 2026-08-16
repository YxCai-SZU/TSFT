#include <stdint.h>

/*@
    predicate valid_range(integer a, integer p) =
        0 <= a && a <= 100 &&
        0 <= p && p <= 100;

    logic integer compute_result(integer a, integer p) =
        (a * 3 + p) / 2;

    lemma result_nonnegative:
        \forall integer a, p;
        valid_range(a, p) ==> compute_result(a, p) >= 0;
*/

/*@
    requires valid_range(a, p);
    ensures \result >= 0;
    ensures \result == compute_result(a, p);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t p)
{
    uint32_t sum;
    uint32_t result;

    sum = a * 3 + p;
    //@ assert sum == a * 3 + p;
    
    result = sum / 2;
    //@ assert result == sum / 2;
    
    //@ assert result == compute_result(a, p);
    
    return (int32_t)result;
}
