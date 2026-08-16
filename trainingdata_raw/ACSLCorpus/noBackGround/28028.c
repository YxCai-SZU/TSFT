#include <stdint.h>

/*@
    requires (0 <= (x) <= 0x60000000);
    ensures \result == ((x) * (x) * (x));
*/
int32_t func(int32_t x)
{
    //@ assert (0 <= (x) <= 0x60000000);
    //@ assert x * x <= 0x60000000 * 0x60000000;
    //@ assert x * x * x <= 0x60000000 * 0x60000000 * 0x60000000;
    
    int32_t result;
    result = x * x * x;
    return result;
}
