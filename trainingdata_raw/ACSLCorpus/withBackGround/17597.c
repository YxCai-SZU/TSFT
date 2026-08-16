#include <stddef.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer conditional_diff(integer x, integer y) =
        x > y ? x - y : 0;

    lemma sum_bound:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) &&
            valid_range(c) && valid_range(d) ==>
            conditional_diff(a, b) + conditional_diff(c, d) <= 200;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result >= 0 && \result <= 200;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c, size_t d)
{
    size_t sum = 0;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);

    if (a > b)
    {
        sum += a - b;
    }

    if (c > d)
    {
        sum += c - d;
    }

    //@ assert sum == conditional_diff(a, b) + conditional_diff(c, d);
    //@ assert sum <= 200;

    return sum;
}
