#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer min(integer x, integer y) = x < y ? x : y;

    logic integer func_spec(integer a, integer b, integer c, integer d) =
        min(a, b) + min(c, d);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == func_spec(a, b, c, d);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    uint64_t min_ab;
    uint64_t min_cd;
    uint64_t result;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    
    min_ab = a < b ? a : b;
    //@ assert min_ab == min(a, b);
    
    min_cd = c < d ? c : d;
    //@ assert min_cd == min(c, d);
    
    result = min_ab + min_cd;
    //@ assert result == min(a, b) + min(c, d);
    
    return result;
}
