#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 20 && 1 <= b <= 20;

    logic integer compute_result(integer a, integer b) =
        a < 10 && b < 10 ? a * b : -1;

    lemma multiplication_bounds:
        \forall integer a, b;
            a < 10 && b < 10 && 1 <= a && 1 <= b ==> a * b < 10000;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;

    //@ assert valid_range(a, b);
    
    if (a >= 10 || b >= 10)
    {
        //@ assert a >= 10 || b >= 10;
        return -1;
    }

    //@ assert a < 10 && b < 10;
    //@ assert 1 <= a && 1 <= b;
    //@ assert a * b < 10000;
    
    result = (int32_t)(a * b);
    
    //@ assert result == (int32_t)(a * b);
    return result;
}
