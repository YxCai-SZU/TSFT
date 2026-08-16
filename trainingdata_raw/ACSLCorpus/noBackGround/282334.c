#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    ensures 0 <= \result <= 10000;
*/
uint32_t func(uint32_t n, uint32_t a) {
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert n * n <= 10000;
    
    result = n * n - a;
    
    //@ assert result == ((n) * (n) - (a));
    //@ assert 0 <= result <= 10000;
    
    return result;
}
