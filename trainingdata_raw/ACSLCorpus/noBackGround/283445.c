#include <stdint.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result >= 1;
    ensures \result <= x;
    ensures \result == 1 || \result == 2 || \result == 5 || 
            \result == 6 || \result == 4 || \result == 3;
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    uint32_t x_unsigned;
    int32_t result;
    
    //@ assert (1 <= (x) <= 100);
    
    if (x < 0) {
        x_unsigned = (uint32_t)(-x);
    } else {
        x_unsigned = (uint32_t)x;
    }
    
    if (x_unsigned % 5 == 0 || x_unsigned % 5 == 2 || x_unsigned % 5 == 4) {
        result = 2;
    } else {
        result = 1;
    }
    
    //@ assert result == 1 || result == 2 || result == 5 || result == 6 || result == 4 || result == 3;
    
    return result;
}
