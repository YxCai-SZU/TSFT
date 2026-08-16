#include <stdint.h>

/*@
    requires (0 <= (a) < 0x80000000) && (0 <= (b) < 0x80000000);
    ensures \result == ((a) | (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;

    //@ assert (0 <= (a) < 0x80000000) && (0 <= (b) < 0x80000000);
    result = a | b;
    //@ assert result == ((a) | (b));

    return result;
}
