#include <stdint.h>

/*@
    requires (0 <= (r) <= 4500 && 0 <= (g) <= 4500);
    ensures \result == (2 * (g) - (r));
    assigns \nothing;
*/
int32_t func(int32_t r, int32_t g)
{
    int32_t result;
    //@ assert (0 <= (r) <= 4500 && 0 <= (g) <= 4500);
    result = 2 * g - r;
    //@ assert result == (2 * (g) - (r));
    return result;
}
