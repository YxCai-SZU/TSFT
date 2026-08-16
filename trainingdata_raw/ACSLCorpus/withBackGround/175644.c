#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (a - b * 2) || \result == 0;
    ensures \result <= a;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    
    //@ assert valid_range(a) && valid_range(b);
    
    if (a > b * 2)
    {
        result = a - b * 2;
    }
    else
    {
        result = 0;
    }
    
    //@ assert result == (a - b * 2) || result == 0;
    //@ assert result <= a;
    
    return result;
}
