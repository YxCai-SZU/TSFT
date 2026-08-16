#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert a * b <= 10000;
    
    result = a * b;
    return result;
}
