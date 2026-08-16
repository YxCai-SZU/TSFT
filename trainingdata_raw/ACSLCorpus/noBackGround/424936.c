#include <stdint.h>

/*@
    requires ((x) <= 0xFFFFFFFFU / 2);
    ensures \result == ((integer)((int)(x)));
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    //@ assert ((x) <= 0xFFFFFFFFU / 2);
    int32_t result = (int32_t)x;
    //@ assert result == ((integer)((int)(x)));
    return result;
}
