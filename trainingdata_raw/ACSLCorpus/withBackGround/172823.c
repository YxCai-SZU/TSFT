#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer min(integer x, integer y) = x < y ? x : y;

    lemma min_sum_range:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            min(a, b) + min(c, d) >= 2 && min(a, b) + min(c, d) <= 20000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t min_ab;
    uint32_t min_cd;
    uint32_t result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }

    //@ assert valid_range(min_ab);
    //@ assert valid_range(min_cd);
    //@ assert min_ab + min_cd >= 2;
    //@ assert min_ab + min_cd <= 20000;

    result = min_ab + min_cd;

    //@ assert result == a + c || result == a + d || result == b + c || result == b + d;
    return result;
}
