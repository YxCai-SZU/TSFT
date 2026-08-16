#include <stdint.h>

/*@
    requires (1 <= (x) <= 20) && (1 <= (y) <= 20) && (1 <= (z) <= 20);
    ensures \result == (((x) + (y)) * (z));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z) {
    // Variable declarations at top of scope
    uint32_t sum;
    uint32_t result;

    //@ assert (1 <= (x) <= 20);
    //@ assert (1 <= (y) <= 20);
    //@ assert (1 <= (z) <= 20);
    
    //@ assert x + y <= 40;
    sum = x + y;
    
    //@ assert sum * z <= 800;
    //@ assert sum * z >= 1;
    result = sum * z;
    
    //@ assert result == (((x) + (y)) * (z));
    return result;
}
