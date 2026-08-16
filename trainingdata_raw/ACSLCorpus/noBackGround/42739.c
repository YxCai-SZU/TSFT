#include <stdint.h>

/*@
    requires ((x) >= 0 && (y) >= 0 && (x) <= 32 && (y) <= 32);
    ensures \result == ((x) * (y));
    ensures \result >= 0;
    ensures \result <= 32 * 32;
*/
uint32_t func(uint32_t x, uint32_t y) {
    uint32_t ans;
    
    //@ assert ((x) >= 0 && (y) >= 0 && (x) <= 32 && (y) <= 32);
    //@ assert ((x) * (y)) >= 0;
    //@ assert ((x) * (y)) <= 32 * 32;
    
    ans = x * y;
    
    //@ assert ans == ((x) * (y));
    //@ assert ans >= 0;
    //@ assert ans <= 32 * 32;
    
    return ans;
}
