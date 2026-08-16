#include <stdint.h>
#include <limits.h>

/*@
    predicate valid_input(integer a0, integer a1, integer a2, integer a3, integer k) =
        0 <= a0 && a0 <= 23 &&
        0 <= a1 && a1 <= 59 &&
        0 <= a2 && a2 <= 23 &&
        0 <= a3 && a3 <= 59 &&
        0 <= k && k <= 100000 &&
        a0 * 60 + a1 <= a2 * 60 + a3;

    logic integer total_minutes(integer a, integer b) = a * 60 + b;

    lemma subtraction_bounds:
        \forall integer a0, a1, a2, a3, k;
        valid_input(a0, a1, a2, a3, k) ==>
        total_minutes(a2, a3) - total_minutes(a0, a1) - k <= INT_MAX;
*/

/*@
    requires valid_input(a0, a1, a2, a3, k);
    ensures \result == (int32_t)(a2 * 60 + a3 - a0 * 60 - a1 - k);
*/
int32_t func(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t k)
{
    //@ assert a0 * 60 + a1 <= a2 * 60 + a3;
    uint32_t s = a0 * 60 + a1;
    uint32_t t = a2 * 60 + a3;
    //@ assert s <= t;
    //@ assert k <= 100000;
    //@ assert t - s - k <= INT_MAX;
    int32_t ans = (int32_t)t - (int32_t)s - (int32_t)k;
    //@ assert ans == (int32_t)(t - s - k);
    return ans;
}
