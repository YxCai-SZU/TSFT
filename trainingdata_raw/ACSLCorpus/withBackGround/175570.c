#include <stdint.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 10000;
*/

/*@
    lemma mul_bounds:
        \forall integer x, integer y;
            in_range(x) && in_range(y) ==> x * y >= 1 && x * y <= 10000 * 10000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t ab;
    uint32_t cd;
    uint32_t result;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);

    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;

    //@ assert a * b >= 1;
    //@ assert c * d >= 1;

    ab = a * b;
    cd = c * d;

    if (ab > cd) {
        result = ab;
    } else {
        result = cd;
    }

    //@ assert result == ab || result == cd;
    //@ assert result >= 1;

    return result;
}
