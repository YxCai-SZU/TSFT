#include <stdint.h>

/*@
    requires (0 <= (x) <= 1);
    ensures \result == 1 - (int)x;
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    int32_t result;
    
    //@ assert (0 <= (x) <= 1);
    if (x == 1) {
        //@ assert x == 1;
        result = 0;
    } else {
        //@ assert x == 0;
        result = 1;
    }
    
    return result;
}
