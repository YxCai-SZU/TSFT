#include <stdint.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 100;

    logic integer compute_result(integer a, integer b) =
        a > b * 2 ? a - b * 2 : 0;

    lemma result_non_negative:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> compute_result(a, b) >= 0;

    lemma result_cases:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 
        compute_result(a, b) == a - b * 2 || compute_result(a, b) == 0;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == a - b * 2 || \result == 0;
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Declare all variables at the top
    uint32_t result;

    //@ assert valid_range(a) && valid_range(b);
    
    if (a > b * 2)
    {
        //@ assert a >= b * 2 && a - b * 2 >= 0;
        result = a - b * 2;
    }
    else
    {
        //@ assert b * 2 >= a && 0 <= a && 0 <= b * 2;
        result = 0;
    }

    //@ assert result == a - b * 2 || result == 0;
    //@ assert result >= 0;
    
    return result;
}
