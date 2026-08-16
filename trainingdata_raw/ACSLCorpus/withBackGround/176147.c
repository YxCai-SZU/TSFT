#include <stdint.h>

/*@
    predicate non_negative(integer v) = v >= 0;
    predicate sum_in_range(integer x, integer y) = x + y < 0x80000000;
*/

/*@
    requires non_negative(x);
    requires non_negative(y);
    requires sum_in_range(x, y);
    ensures \result == x + y;
    assigns \nothing;
*/
int32_t func(int32_t x, int32_t y)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert x + y < 0x80000000;
    
    result = x + y;
    return result;
}
