#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t result;
    //@ assert (1 <= (r) <= 100);
    //@ assert 3 * r <= 3 * 100;
    //@ assert 3 * r * r <= 3 * 100 * 100;
    result = 3 * r * r;
    return result;
}
