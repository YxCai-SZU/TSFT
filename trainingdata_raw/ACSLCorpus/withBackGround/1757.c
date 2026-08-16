#include <stdint.h>

/*@
    predicate is_valid_params(integer x, integer t) =
        1 <= x <= 1000000000 &&
        1 <= t <= 1000000000;

    logic integer func_spec(integer x, integer t) =
        x > t ? x - t : 0;

    lemma func_result_nonnegative:
        \forall integer x, t;
        is_valid_params(x, t) ==> func_spec(x, t) >= 0;

    lemma func_result_cases:
        \forall integer x, t;
        is_valid_params(x, t) ==> 
        (func_spec(x, t) == x - t || func_spec(x, t) == 0);
*/

/*@
    requires is_valid_params(x, t);
    ensures \result >= 0;
    ensures \result == x - t || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t t)
{
    int64_t result;
    
    //@ assert is_valid_params(x, t);
    
    if (x > t)
    {
        //@ assert x > t;
        result = x - t;
    }
    else
    {
        //@ assert x <= t;
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == x - t || result == 0;
    
    return result;
}
