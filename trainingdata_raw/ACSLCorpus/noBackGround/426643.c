#include <stdint.h>

/*@
    requires ((x) > 0 && (y) > 0 && (z) > 0 &&
        (x) * (y) <= 1000 &&
        (x) * (y) * (z) <= 1000);
    ensures \result == ((x) * (y) * (z));
    assigns \nothing;
*/
int32_t func(int32_t x, int32_t y, int32_t z)
{
    //@ assert x > 0 && y > 0 && z > 0;
    //@ assert x * y <= 1000;
    //@ assert x * y * z <= 1000;
    
    int32_t result;
    result = x * y * z;
    return result;
}
