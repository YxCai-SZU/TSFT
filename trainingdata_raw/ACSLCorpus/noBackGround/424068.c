#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == 0 || \result == -1 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint64_t s;
    
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    //@ assert ((c) * (d)) <= 10000 * 10000;
    
    s = (uint64_t)c * (uint64_t)d;
    
    if (a > (uint32_t)s) {
        return -1;
    } else if (a == (uint32_t)s) {
        return 0;
    } else {
        return 1;
    }
}
