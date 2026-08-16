#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * 3);
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    int32_t pi;
    int32_t result;

    pi = 3;
    result = 2 * r * pi;

    //@ assert result == 2 * r * 3;

    return result;
}
