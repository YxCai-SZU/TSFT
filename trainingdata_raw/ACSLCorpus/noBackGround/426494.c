#include <stdint.h>

/*@
    requires ((x) <= 0xFFFFFFFF && (y) <= 0xFFFFFFFF && (y) > 0);
    ensures \result == (((integer)x) / ((integer)y));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    //@ assert y > 0;
    
    uint32_t ans;
    
    //@ assert (((integer)x) / ((integer)y)) <= 0xFFFFFFFF;
    
    ans = x / y;
    
    //@ assert ans == (((integer)x) / ((integer)y));
    return ans;
}
