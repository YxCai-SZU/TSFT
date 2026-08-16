#include <stdint.h>

/*@
    requires (0 <= (x) <= 0xFFFFFFFF);
    ensures \result == x;
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    //@ assert (0 <= (x) <= 0xFFFFFFFF);
    return x;
}
