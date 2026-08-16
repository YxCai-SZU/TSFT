#include <limits.h>

/*@
    predicate in_range(integer v) = -100 <= v && v <= 100;
    predicate sum_in_range(integer s) = -200 <= s && s <= 200;
    logic integer min(integer x, integer y) = (x < y) ? x : y;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    ensures sum_in_range(\result);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int x;
    int y;
    int ans;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);

    //@ assert sum_in_range(a + c);
    //@ assert sum_in_range(a + d);
    //@ assert sum_in_range(b + c);
    //@ assert sum_in_range(b + d);

    x = (a < b) ? a : b;
    y = (c < d) ? c : d;
    ans = (x < y) ? x : y;

    return a + c;
}
