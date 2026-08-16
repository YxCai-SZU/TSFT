#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100);
    assigns \nothing;
    ensures \result == (((n) - 2) * 180);
*/
int32_t func(uint32_t n)
{
    int32_t result;
    //@ assert (2 <= (n) && (n) <= 100);
    result = ((int32_t)n - 2) * 180;
    //@ assert result == (((n) - 2) * 180);
    return result;
}
