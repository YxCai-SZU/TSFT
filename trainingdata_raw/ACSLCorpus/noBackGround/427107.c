#include <stdint.h>

/*@
    requires 0 <= x && x <= 9;
    requires 0 <= a && a <= 9;
    ensures (x >= a && \result == 10) || (x < a && \result == 0);
    assigns \nothing;
*/
int32_t func(uint32_t x, uint32_t a) {
    int32_t result;
    
    if (x >= a) {
        //@ assert ((x) >= (a));
        result = 10;
    } else {
        //@ assert ((x) < (a));
        result = 0;
    }
    
    return result;
}
