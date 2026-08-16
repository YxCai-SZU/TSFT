#include <stdint.h>

/*@
    requires 0 <= x && x <= 100;
    requires 0 <= y && y <= 100;
    ensures \result == (x * y + 100 - 1) / 100;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y) {
    uint32_t result;
    
    //@ assert x * y <= 10000;
    //@ assert 100 - 1 <= 10000;
    
    result = (x * y + 100 - 1) / 100;
    return result;
}
