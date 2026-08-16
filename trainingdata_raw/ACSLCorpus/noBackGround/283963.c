#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at scope top
    int32_t res;

    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert 3 * r >= 3 * 1;
    //@ assert 3 * r <= 3 * 100;
    //@ assert 3 * r * r <= 30000;

    res = 3 * r * r;
    //@ assert res == (3 * (r) * (r));
    return res;
}
