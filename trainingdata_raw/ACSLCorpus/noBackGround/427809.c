#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t result;
    //@ assert (1 <= (n) && (n) <= 100);
    result = (n + 1) / 2;
    //@ assert result == (((n) + 1) / 2);
    return result;
}
