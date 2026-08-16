#include <stdint.h>
/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == ((a) * ((a) + 1) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t a) {
    // Variable declarations at scope top
    uint64_t result;
    
    //@ assert (1 <= (a) && (a) <= 100);
    
    //@ assert ((a) * ((a) + 1) / 2) <= ((100) * ((100) + 1) / 2);
    
    result = a * (a + 1) / 2;
    
    //@ assert result == ((a) * ((a) + 1) / 2);
    
    return result;
}
