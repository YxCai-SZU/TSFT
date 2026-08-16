#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 0 <= x <= 1000000000;
    
    logic integer compute_result(integer x) =
        x < 0 ?
            -(((-x) / 500) * 1000 + (((-x) % 500) / 5) * 5) :
            ((x / 500) * 1000 + ((x % 500) / 5) * 5);
    
    lemma result_bounds:
        \forall integer x;
            is_valid_input(x) ==>
            compute_result(x) >= 0 &&
            compute_result(x) <= 2 * x + 1;
*/

/*@
    requires is_valid_input(x);
    ensures \result >= 0;
    ensures \result <= 2 * x + 1;
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    uint64_t x_unsigned;
    uint64_t result_unsigned;
    int64_t result;
    
    //@ assert x == x;
    
    if (x < 0)
    {
        x_unsigned = (uint64_t)(-x);
    }
    else
    {
        x_unsigned = (uint64_t)x;
    }
    
    result_unsigned = (x_unsigned / 500) * 1000 + ((x_unsigned % 500) / 5) * 5;
    
    if (x < 0)
    {
        result = -(int64_t)result_unsigned;
    }
    else
    {
        result = (int64_t)result_unsigned;
    }
    
    //@ assert result >= 0 && result <= 2 * x + 1;
    
    return result;
}
