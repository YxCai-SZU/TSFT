#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer min(integer x, integer y) = (x < y) ? x : y;

    logic integer func_spec(integer a, integer b, integer c, integer d) =
        min(a, b) + min(c, d);
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    requires valid_range(d);
    ensures \result == func_spec(a, b, c, d);
    ensures 1 <= \result <= 20000;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int ans;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    //@ assert min_ab == min(a, b);

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }
    //@ assert min_cd == min(c, d);

    ans = min_ab + min_cd;
    //@ assert ans == func_spec(a, b, c, d);

    //@ assert 1 <= ans;
    //@ assert ans <= 20000;

    return ans;
}
