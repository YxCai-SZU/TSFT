#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 3;
    predicate distinct(integer a, integer b) = a != b;
    logic integer compute_third(integer a, integer b) = 6 - a - b;
*/

/*@
    requires valid_range(a) && valid_range(b) && distinct(a, b);
    ensures \result == compute_third(a, b);
    ensures 1 <= \result <= 3;
    ensures \result != a && \result != b;
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    // Variable declarations at top of scope
    size_t ret;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert distinct(a, b);
    //@ assert compute_third(a, b) >= 1;
    //@ assert compute_third(a, b) <= 3;

    ret = 6 - a - b;

    return ret;
}
