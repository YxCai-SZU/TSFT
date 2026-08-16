#include <stdint.h>

/*@
    requires x <= 1;
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    
    //@ assert x == 0 || x == 1;
    
    //@ assert x == 0 ==> (1 - (x)) == 1;
    //@ assert x == 1 ==> (1 - (x)) == 0;
    
    result = 1 - x;
    
    //@ assert (x == 0 && result == 1) || (x == 1 && result == 0);
    
    return result;
}
