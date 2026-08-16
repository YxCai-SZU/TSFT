#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 12 &&
        1 <= (b) && (b) <= 31);
    ensures ((\result) <= (a) && (\result) >= 1);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    
    //@ assert (1 <= (a) && (a) <= 12 &&         1 <= (b) && (b) <= 31);
    
    if (a <= b) {
        result = a;
    } else {
        result = a - 1;
    }
    
    //@ assert ((result) <= (a) && (result) >= 1);
    
    return result;
}
