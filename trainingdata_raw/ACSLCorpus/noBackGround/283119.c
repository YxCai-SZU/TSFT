#include <stdint.h>

/*@
    requires ((x) <= 1000);
    ensures ((\result) == (x) * ((x) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    //@ assert x * (x + 1) / 2 <= (1000 * 1001 / 2);
    result = x * (x + 1) / 2;
    return result;
}
