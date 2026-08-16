#include <stddef.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
size_t func(size_t r)
{
    // Variable declarations at scope top
    size_t res;

    //@ assert 1 <= r <= 100;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 300 * r;

    res = 3 * r * r;
    //@ assert res == 3 * r * r;
    return res;
}
