#include <stddef.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer max_of_three(integer a, integer b, integer c) =
        (a >= b && a >= c) ? a : ((b >= a && b >= c) ? b : c);

    lemma max_le_sum: \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        max_of_three(a, b, c) <= a + b + c;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result <= a + b + c;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c)
{
    size_t max_ab;
    size_t max_bc;
    size_t max_ac;
    size_t result;

    //@ assert a <= a + b + c;
    //@ assert b <= a + b + c;
    //@ assert c <= a + b + c;

    if (a > b) {
        max_ab = a;
    } else {
        max_ab = b;
    }

    if (b > c) {
        max_bc = b;
    } else {
        max_bc = c;
    }

    if (a > c) {
        max_ac = a;
    } else {
        max_ac = c;
    }

    if (max_ab > max_bc) {
        result = max_ab;
    } else {
        result = max_bc;
    }

    if (max_ac > result) {
        return max_ac;
    } else {
        return result;
    }
}
