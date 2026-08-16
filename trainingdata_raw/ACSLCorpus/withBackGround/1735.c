#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x && x <= 100;

    logic integer func_result(integer a, integer b, integer c) =
        (b / a < c) ? (b / a) : c;

    lemma result_bound: \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        func_result(a, b, c) <= c;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == func_result(a, b, c);
    ensures \result <= c;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c);
    
    if (b / a < c)
    {
        result = b / a;
        //@ assert result == b / a;
        //@ assert result <= c;
    }
    else
    {
        result = c;
        //@ assert result == c;
        //@ assert result <= c;
    }

    //@ assert result == func_result(a, b, c);
    //@ assert result <= c;
    
    return result;
}
