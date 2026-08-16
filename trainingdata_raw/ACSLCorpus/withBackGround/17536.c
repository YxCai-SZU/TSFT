#include <stdint.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 50;

    logic integer func_spec(integer a, integer b, integer c) =
        (a > b + c + 1) ? (b + c + 1 + a) : (b + c + 1);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result <= b + c + 1 + a;
    ensures \result >= b + c + 1;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;
    
    //@ assert valid_range(a) && valid_range(b) && valid_range(c);
    
    if (a > b + c + 1)
    {
        //@ assert a > b + c + 1;
        result = b + c + 1 + a;
    }
    else
    {
        //@ assert a <= b + c + 1;
        result = b + c + 1;
    }
    
    //@ assert result <= b + c + 1 + a;
    //@ assert result >= b + c + 1;
    return result;
}
