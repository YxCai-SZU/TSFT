#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 20;
    logic integer diff(integer x, integer y) = x - y;
    logic integer product(integer x, integer y) = x * y;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == diff(a, c) * diff(b, d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int ac;
    int bd;
    int res;

    //@ assert -19 <= a - c <= 19;
    ac = a - c;
    //@ assert -19 <= b - d <= 19;
    bd = b - d;
    //@ assert -19 <= ac <= 19;
    //@ assert -19 <= bd <= 19;
    //@ assert -361 <= ac * bd <= 361;
    res = ac * bd;
    //@ assert res == (a - c) * (b - d);
    return res;
}
