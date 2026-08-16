#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    requires (1 <= (b) <= 10);
    requires (1 <= (c) <= 10);
    ensures \result == ((a) + (b) + 10 * (c));
    ensures \result >= 3;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t result;

    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    
    result = a + b + 10 * c;
    
    //@ assert result == ((a) + (b) + 10 * (c));
    //@ assert result >= 3;
    
    return result;
}
