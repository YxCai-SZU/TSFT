#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 10) && (1 <= (y) && (y) <= 10) && (1 <= (z) && (z) <= 10);
    ensures \result == (x * y) * z;
    assigns \nothing;
*/
int32_t func(int32_t x, int32_t y, int32_t z) {
    // Variable declarations at scope top
    int32_t xy;
    int32_t result;
    
    //@ assert (1 <= (x) && (x) <= 10);
    //@ assert (1 <= (y) && (y) <= 10);
    //@ assert (1 <= (z) && (z) <= 10);
    //@ assert x * y <= 100;
    //@ assert (x * y) * z <= 1000;
    
    xy = x * y;
    result = xy * z;
    return result;
}
