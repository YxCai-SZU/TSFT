#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 10;
    predicate is_arithmetic_progression(integer a, integer b, integer c) = b - a == c - b;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert (b - a == c - b) || (b - a != c - b);

    result = (b - a == c - b);
    return result;
}
