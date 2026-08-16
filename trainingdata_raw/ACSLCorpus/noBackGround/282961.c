#include <stdint.h>
/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (t) <= 20);
    ensures \result == (((t) / (a)) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t t) {
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert (1 <= (a) <= 20);
    //@ assert (1 <= (b) <= 20);
    //@ assert (1 <= (t) <= 20);
    
    //@ assert t / a <= 20;
    //@ assert (t / a) * b <= 400;
    
    result = (t / a) * b;
    
    //@ assert result == (((t) / (a)) * (b));
    return result;
}
