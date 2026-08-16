#include <stdbool.h>

/*@
    predicate in_range(integer a, integer low, integer high) =
        low <= a && a <= high;

    logic integer diff(integer c, integer a) = c - a;

    predicate condition_holds(integer a, integer b, integer c) =
        diff(c, a) >= 0 && diff(c, a) <= b;
*/

/*@
    requires in_range(a, 1, 500);
    requires in_range(b, 1, 500);
    requires in_range(c, 1, 1000);
    ensures \result == (diff(c, a) >= 0 && diff(c, a) <= b);
*/
bool func(int a, int b, int c)
{
    bool ans;
    int tmp;

    //@ assert in_range(a, 1, 500);
    //@ assert in_range(b, 1, 500);
    //@ assert in_range(c, 1, 1000);

    tmp = c - a;
    if (tmp >= 0 && tmp <= b) {
        ans = true;
    } else {
        ans = false;
    }

    //@ assert ans == (tmp >= 0 && tmp <= b);
    return ans;
}
