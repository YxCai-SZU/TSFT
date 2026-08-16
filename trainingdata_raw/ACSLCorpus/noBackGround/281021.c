#include <stdint.h>

/*@
    requires (1 <= (H) <= 20 &&
        1 <= (W) <= 20 &&
        1 <= (h) <= (H) &&
        1 <= (w) <= (W));
    ensures \result == (((H) - (h)) * ((W) - (w)));
    assigns \nothing;
*/
int32_t func(uint32_t H, uint32_t W, uint32_t h, uint32_t w)
{
    // Variable declarations at scope top
    int32_t result;

    // Precondition implies these bounds
    //@ assert H - h >= 0;
    //@ assert H - h <= 19;
    //@ assert W - w >= 0;
    //@ assert W - w <= 19;
    
    // Critical verification property for postcondition
    //@ assert (H - h) * (W - w) >= 0;
    
    result = (int32_t)(H - h) * (int32_t)(W - w);
    return result;
}
