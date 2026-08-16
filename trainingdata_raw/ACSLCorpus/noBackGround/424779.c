#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * 2 * 3);
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    int32_t pi = 3;
    int32_t result;

    //@ assert (1 <= (r) <= 100);
    //@ assert r * 2 * 3 == 6 * r;
    //@ assert 6 * r <= 600;

    result = r * 2 * pi;

    //@ assert result == r * 2 * 3;
    return result;
}
