#include <stddef.h>

/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    logic integer area(integer r) = 3 * r * r;
    lemma area_bounds: \forall integer r; r_in_range(r) ==> area(r) <= 30000;
*/

/*@
    requires r_in_range(r);
    ensures \result == area(r);
    assigns \nothing;
*/
size_t func(size_t r)
{
    // Variable declarations at top of scope
    size_t res;

    //@ assert 1 * r <= 100;
    //@ assert r <= 100;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 300 * 100;

    res = 3 * r * r;
    return res;
}
