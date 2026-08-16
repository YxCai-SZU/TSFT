#include <stdint.h>

/*@
    predicate is_less(integer x, integer a) = x < a;
    predicate is_greater_equal(integer x, integer a) = x >= a;
*/

/*@
    requires 0 <= x <= 9;
    requires 0 <= a <= 9;
    ensures is_less(x, a) ==> \result == 0;
    ensures is_greater_equal(x, a) ==> \result == 10;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t a)
{
    uint32_t result;
    
    if (x < a)
    {
        //@ assert is_less(x, a);
        result = 0;
    }
    else
    {
        //@ assert is_greater_equal(x, a);
        result = 10;
    }
    
    return result;
}
