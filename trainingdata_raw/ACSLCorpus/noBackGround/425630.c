#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result <= ((b) * (c));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t x;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    // Apply lemma
    //@ assert ((b) * (c)) <= 10000;
    
    x = b * c;
    
    //@ assert x == ((b) * (c));
    //@ assert x <= 10000;
    
    if (a > x) {
        //@ assert x <= ((b) * (c));
        return x;
    } else {
        //@ assert a <= ((b) * (c));
        return a;
    }
}
