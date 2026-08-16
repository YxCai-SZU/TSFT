#include <stdint.h>
#include <limits.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 10000;
    logic integer min(integer x, integer y) = x < y ? x : y;
    logic integer sum(integer x, integer y) = x + y;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == a + c || \result == b + c || \result == a + d || \result == b + d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t min_ab;
    uint32_t min_cd;
    uint32_t ans;

    //@ assert in_range(a) && in_range(b);
    //@ assert in_range(c) && in_range(d);

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    //@ assert min_ab == min(a, b);

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }
    //@ assert min_cd == min(c, d);

    //@ assert in_range(min_ab);
    //@ assert in_range(min_cd);
    //@ assert min_ab + min_cd <= UINT32_MAX;

    ans = min_ab + min_cd;
    //@ assert ans == sum(min_ab, min_cd);
    //@ assert ans == a + c || ans == b + c || ans == a + d || ans == b + d;

    return ans;
}
