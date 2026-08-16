#include <stdint.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == ((800 * (x)) - (200 * ((x) / 15)));
    assigns \nothing;
*/
int32_t func(uint32_t x) {
    // Variable declarations at top
    int32_t result;
    
    //@ assert (1 <= (x) <= 100);
    //@ assert 800 * x <= 80000;
    //@ assert 200 * (x / 15) <= 1200;
    
    result = 800 * (int32_t)x - 200 * (int32_t)(x / 15);
    
    //@ assert result == ((800 * (x)) - (200 * ((x) / 15)));
    return result;
}
