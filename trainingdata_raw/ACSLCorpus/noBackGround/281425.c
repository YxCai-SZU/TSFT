#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert (1 <= (r) <= 100);
    //@ assert 1 * r <= 100 * 100;
    //@ assert 3 * r <= 3 * 100;
    //@ assert 3 * r * r <= 3 * 100 * 100;

    result = 3 * r * r;
    //@ assert result == (3 * (r) * (r));

    return result;
}
