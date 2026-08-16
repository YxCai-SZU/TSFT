#include <stdint.h>
/*@
    requires (2 <= (a) <= 100) && (2 <= (b) <= 100);
    ensures \result == ((a) * (b) - ((a) + (b) - 1));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at scope top
    uint32_t result;

    // Precondition assertions
    //@ assert (2 <= (a) <= 100);
    //@ assert (2 <= (b) <= 100);

    // Mathematical property verification
    //@ assert a * b <= 10000;
    //@ assert a + b <= 200;
    //@ assert a + b - 1 <= 199;
    //@ assert a * b >= a + b - 1;

    result = a * b - (a + b - 1);
    
    // Postcondition verification
    //@ assert result == ((a) * (b) - ((a) + (b) - 1));
    
    return result;
}
