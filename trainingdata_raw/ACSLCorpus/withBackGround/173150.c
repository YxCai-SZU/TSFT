#include <stdbool.h>

/*@
    predicate in_range(integer x) = -100 <= x <= 100;
    predicate within_bounds(integer a, integer b, integer c) = c >= a && c <= b;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == 1 <==> within_bounds(a, b, c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool ans;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert within_bounds(a, b, c) ==> within_bounds(a, b, c);

    ans = (c >= a) && (c <= b);
    return ans;
}
