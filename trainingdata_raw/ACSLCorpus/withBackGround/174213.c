#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b) =
        a >= 1 && a <= 100 && b >= 1 && b <= 100;

    logic integer compute_result(integer a, integer b) =
        a - b * 2;

    lemma result_bounds:
        \forall integer a, b;
        valid_inputs(a, b) ==> compute_result(a, b) <= 100;

    lemma result_nonnegative_or_zero:
        \forall integer a, b;
        valid_inputs(a, b) ==> 
        compute_result(a, b) > 0 ==> compute_result(a, b) == a - b * 2;
*/

/*@
    requires valid_inputs(a, b);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t result;
    int64_t temp;

    //@ assert b * 2 <= 200;
    temp = b * 2;
    
    //@ assert a - temp <= 100;
    result = a - temp;
    
    if (result > 0)
    {
        //@ assert result == a - b * 2;
        return result;
    }
    else
    {
        //@ assert result <= 0;
        result = 0;
        return result;
    }
}
