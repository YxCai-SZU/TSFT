#include <stdbool.h>

/*@
    predicate a_in_bounds(integer a) =
        a >= -9223372036854775808 && a <= 9223372036854775807;
    predicate b_in_bounds(integer b) =
        b >= -9223372036854775808 && b <= 9223372036854775807;
    predicate c_in_bounds(integer c) =
        c >= -9223372036854775808 && c <= 9223372036854775807;
    predicate a_le_b(integer a, integer b) = a <= b;
    predicate c_in_range(integer a, integer b, integer c) =
        a <= c && c <= b;
*/

/*@
    requires a_in_bounds(a) && b_in_bounds(b) && c_in_bounds(c);
    requires a_le_b(a, b);
    ensures \result == (a <= c && c <= b);
*/
bool func(long long a, long long b, long long c)
{
    //@ assert a <= b;
    return a <= c && c <= b;
}
