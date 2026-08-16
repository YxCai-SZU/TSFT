#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = 1 <= x <= 100;

    logic integer diff(integer x, integer y) = x - y;

    lemma diff_bounds:
        \forall integer a, b;
            is_in_range(a) && is_in_range(b) ==> -99 <= diff(a, b) <= 99;
*/

/*@
    requires is_in_range(a);
    requires is_in_range(b);
    requires is_in_range(c);
    ensures \result == (c - b == b - a);
*/
bool func(long a, long b, long c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert -99 <= c - b <= 99;
    //@ assert -99 <= b - a <= 99;

    result = (c - b == b - a);
    return result;
}
