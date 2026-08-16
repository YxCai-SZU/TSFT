#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations
    int64_t res;

    //@ assert 1 <= r <= 100;
    //@ assert (3 * (r) * (r)) >= 3;
    //@ assert (3 * (r) * (r)) <= 30000;
    //@ assert (3 * (r) * (r)) == 3 * r * r;

    res = 3 * r * r;
    return res;
}
