#include <stdint.h>

/*@
    requires (0 <= (r) <= 4500 && 0 <= (g) <= 4500);
    ensures \result == ((g) * 2 - (r));
    assigns \nothing;
*/
int32_t func(int32_t r, int32_t g)
{
    int32_t res;
    //@ assert (0 <= (r) <= 4500 && 0 <= (g) <= 4500);
    res = g * 2 - r;
    //@ assert res == ((g) * 2 - (r));
    return res;
}
