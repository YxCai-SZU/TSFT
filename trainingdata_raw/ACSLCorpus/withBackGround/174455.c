#include <stdint.h>
/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer min(integer x, integer y) = x < y ? x : y;

    lemma ans_bound:
        \forall integer a,b,c,d,min_ab,min_cd,ans;
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) &&
        min_ab == min(a,b) && min_cd == min(c,d) && ans == min_ab + min_cd ==>
        ans <= a + b + c + d;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == min(a,b) + min(c,d);
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t min_ab;
    uint32_t min_cd;
    uint32_t ans;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    //@ assert min_ab == min(a,b);

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }
    //@ assert min_cd == min(c,d);

    ans = min_ab + min_cd;
    //@ assert ans == min(a,b) + min(c,d);

    //@ assert ans <= a + b + c + d;

    return ans;
}
