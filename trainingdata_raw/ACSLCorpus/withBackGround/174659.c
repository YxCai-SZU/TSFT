#include <stdbool.h>

/*@
    predicate in_range(integer v) = 0 <= v && v <= 123;
    predicate ordered(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d) && in_range(e) && in_range(k);
    requires ordered(a, b, c, d, e);
    ensures \result == (k >= e - a || k <= 0);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    bool result;
    //@ assert k >= e - a || k <= 0 ==> (k >= e - a || k <= 0);
    result = (k >= e - a || k <= 0);
    return result;
}
