#include <limits.h>

/*@
    predicate bounds(integer v) = -100 <= v <= 100;
    predicate result_bounds(integer v) = -10000 <= v <= 10000;
*/

/*@
    requires bounds(a) && bounds(b) && bounds(c) && bounds(d);
    ensures \result == a * b || \result == c * d;
    ensures result_bounds(\result);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int x;
    int y;
    int res;

    //@ assert bounds(a) && bounds(b);
    //@ assert -10000 <= a * b <= 10000;
    x = a * b;

    //@ assert bounds(c) && bounds(d);
    //@ assert -10000 <= c * d <= 10000;
    y = c * d;

    //@ assert result_bounds(x) && result_bounds(y);
    res = (x > y) ? x : y;
    //@ assert res == x || res == y;
    return res;
}
