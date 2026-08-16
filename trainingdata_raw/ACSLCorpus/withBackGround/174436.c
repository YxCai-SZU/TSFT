#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_full_or(uint32_t x, uint32_t y) = (x | y) == 0xFFFFFFFF; */

/*@
    requires x <= 0xFFFFFFFF && y <= 0xFFFFFFFF;
    ensures \result == ((x | y) == 0xFFFFFFFF);
    assigns \nothing;
*/
bool func(uint32_t x, uint32_t y)
{
    // Variable declarations at top of scope
    uint32_t z;
    bool result;

    //@ assert x <= 0xFFFFFFFF && y <= 0xFFFFFFFF;
    
    z = x | y;
    
    //@ assert z == (x | y);
    
    result = (z == 0xFFFFFFFF);
    return result;
}
