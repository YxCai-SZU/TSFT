#include <stdint.h>

/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    //@ assert (0 <= (x) <= 1);
    result = 1 - x;
    //@ assert result == (1 - (x));
    //@ assert 0 <= result <= 1;
    return result;
}
