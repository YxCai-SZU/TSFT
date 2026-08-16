#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100) && (1 <= (y) && (y) <= 100) && (1 <= (z) && (z) <= 100);
    ensures ((\result) <= 1000);
    ensures \result <= x * y * z;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    uint32_t result;
    
    //@ assert x * y <= 10000;
    //@ assert x * y * z <= 1000000;
    
    if (x * y * z > 1000) {
        result = 1000;
    } else {
        result = x * y * z;
    }
    
    return result;
}
