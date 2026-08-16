#include <stdint.h>

/*@
    predicate valid_range(integer v) = 0 <= v <= 8;

    logic integer multiply_sum(integer x, integer y, integer z) = x * y + z;

    lemma multiply_bounds: \forall integer x, y; valid_range(x) && valid_range(y) ==> x * y <= 64;
*/

/*@
    requires valid_range(x);
    requires valid_range(y);
    requires valid_range(z);
    ensures \result == multiply_sum(x, y, z);
    ensures \result >= z;
*/
int32_t func(int32_t x, int32_t y, int32_t z)
{
    //@ assert valid_range(x);
    //@ assert valid_range(y);
    //@ assert x * y <= 64;
    
    int32_t t;
    int32_t result;
    
    t = x * y;
    result = t + z;
    
    //@ assert result == multiply_sum(x, y, z);
    //@ assert result >= z;
    
    return result;
}
