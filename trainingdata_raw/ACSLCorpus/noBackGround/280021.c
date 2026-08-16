#include <stdint.h>

/*@
    requires (1 <= (a) <= 12 && 1 <= (b) <= 31);
    ensures \result <= 31;
    ensures \result == b || \result == b - 1;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    
    //@ assert (1 <= (a) <= 12 && 1 <= (b) <= 31);
    
    if (a <= b) {
        result = b;
    } else {
        result = b - 1;
    }
    
    //@ assert result == ((a) <= (b) ? (b) : (b) - 1);
    //@ assert result <= 31;
    
    return result;
}
