#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        0 <= a && a <= 50 &&
        0 <= b && b <= 50 &&
        0 <= c && c <= 50;

    logic integer total_balls(integer a, integer b, integer c) = a + b + c;

    lemma total_balls_range:
        \forall integer a, b, c;
        valid_input(a, b, c) ==> 0 <= total_balls(a, b, c) <= 150;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0 && \result <= 3;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert 0 <= a + b + c <= 150;

    if (a == b && b == c) {
        result = 1;
    } else if (a == b || b == c || a == c) {
        result = 2;
    } else {
        result = 3;
    }

    //@ assert result >= 0 && result <= 3;
    return result;
}
