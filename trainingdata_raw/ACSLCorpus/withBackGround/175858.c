#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer min(integer x, integer y) = x < y ? x : y;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result <= c;
    ensures \result == b / a || \result == c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;
    //@ assert valid_range(a) && valid_range(b) && valid_range(c);
    
    if (b / a < c) {
        result = b / a;
    } else {
        result = c;
    }
    
    //@ assert result <= c;
    //@ assert result == b / a || result == c;
    
    return result;
}
