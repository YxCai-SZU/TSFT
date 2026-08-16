#include <stdint.h>

/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_bounded(integer x) = 0 <= x <= 100;
*/

/*@
    logic integer upper_bound(integer a, integer p) = p + a * 3;
*/

/*@
    lemma result_bounded: \forall integer a, p, r;
        is_bounded(a) && is_bounded(p) && r == (p + a * 3) / 2 ==>
        r <= upper_bound(a, p) && is_nonnegative(r);
*/

/*@
    requires is_bounded(a) && is_bounded(p);
    ensures \result <= upper_bound(a, p) && is_nonnegative(\result);
*/
int64_t func(int64_t a, int64_t p)
{
    // Variable declarations at scope top
    int64_t result;

    //@ assert is_bounded(a);
    //@ assert is_bounded(p);
    //@ assert upper_bound(a, p) >= 0;

    result = (p + a * 3) / 2;

    //@ assert result <= upper_bound(a, p);
    //@ assert result >= 0;

    return result;
}
