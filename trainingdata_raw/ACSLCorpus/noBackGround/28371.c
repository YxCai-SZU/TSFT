#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 23);
    ensures \result == (2 * 24 - (n));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t result;

    x = 48 - (int32_t)n;
    result = 2 * 24 - (int32_t)n;

    //@ assert result == 2 * 24 - (int32_t)n;

    return result;
}
