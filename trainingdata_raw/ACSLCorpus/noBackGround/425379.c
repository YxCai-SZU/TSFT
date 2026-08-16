#include <stdint.h>

/*@
    requires (((a) & 0x000000FF) == ((a) % 256));
    ensures \result == (a & 0x000000FF);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    //@ assert (((a) & 0x000000FF) == ((a) % 256));
    uint32_t result = a & 0x000000FF;
    //@ assert result == (a & 0x000000FF);
    return result;
}
