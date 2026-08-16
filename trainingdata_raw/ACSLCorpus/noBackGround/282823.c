#include <stdint.h>

/*@
    requires 0 <= x <= 10 && 0 <= y <= 10;
    ensures \result == x * y;
    ensures \result <= 100;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y) {
    // Variable declarations at scope top
    uint32_t res;
    
    //@ assert ((x) <= 10 && (y) <= 10);
    
    res = x * y;
    
    //@ assert res == ((x) * (y));
    //@ assert res <= 100;
    
    return res;
}
