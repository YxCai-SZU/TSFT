#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
uint64_t func(uint64_t a) {
    // Variable declarations at scope top
    uint64_t a2;
    uint64_t a3;
    uint64_t result;
    
    //@ assert a >= 1 && a <= 10;
    
    // Calculate a²
    //@ assert a * a <= 100;
    a2 = a * a;
    
    // Calculate a³
    //@ assert a2 * a <= 1000;
    a3 = a2 * a;
    
    // Verify intermediate relationships
    //@ assert a2 >= a;
    //@ assert a3 >= a2;
    
    // Calculate final result
    result = a + a2 + a3;
    
    // Verify final property
    //@ assert result >= a;
    
    return result;
}
