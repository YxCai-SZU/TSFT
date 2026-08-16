#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 1000000000);
    ensures ((\result) % 2 == 0);
    ensures \result >= x;
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    
    if (x % 2 == 0) {
        result = x;
    } else {
        //@ assert x * 2 >= x;
        result = x * 2;
    }
    
    //@ assert ((result) % 2 == 0);
    return result;
}
