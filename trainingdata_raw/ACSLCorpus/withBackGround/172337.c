#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer abs_diff(integer x, integer y) =
        x > y ? x - y : y - x;

    logic integer manhattan(integer a, integer b, integer c, integer d) =
        abs_diff(a, c) + abs_diff(b, d);

    lemma manhattan_bound:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            manhattan(a, b, c, d) <= 20000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == manhattan(a, b, c, d);
    ensures \result <= 20000;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t s1;
    uint32_t s2;
    uint32_t result;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);

    if (a > c) {
        s1 = a - c;
    } else {
        s1 = c - a;
    }

    //@ assert s1 == abs_diff(a, c);

    if (b > d) {
        s2 = b - d;
    } else {
        s2 = d - b;
    }

    //@ assert s2 == abs_diff(b, d);

    result = s1 + s2;

    //@ assert result == manhattan(a, b, c, d);
    //@ assert result <= 20000;

    return result;
}
