#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        c - (a - b);

    lemma result_bounds:
        \forall integer a, b, c;
        valid_params(a, b, c) && compute_result(a, b, c) >= 0 ==>
        compute_result(a, b, c) <= c;
*/

/*@
    requires valid_params(a, b, c);
    ensures \result >= 0 && \result <= c;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    int32_t result;
    //@ assert valid_params(a, b, c);
    
    result = c - (a - b);
    
    if (result < 0)
    {
        //@ assert result < 0;
        return 0;
    }
    else
    {
        //@ assert result >= 0;
        //@ assert result <= c;
        return result;
    }
}
