#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) * (b) + 1) / 2);
    ensures \result >= 1;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert a * b <= 10000;
    
    result = (a * b + 1) / 2;
    
    //@ assert result == (((a) * (b) + 1) / 2);
    //@ assert result >= 1;
    
    return result;
}
