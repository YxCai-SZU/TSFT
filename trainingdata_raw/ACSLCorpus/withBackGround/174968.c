#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 3;
    predicate distinct(integer x, integer y) = x != y;
    predicate result_props(integer res, integer a, integer b) =
        res == 6 - a - b &&
        valid_range(res) &&
        distinct(res, a) &&
        distinct(res, b);
*/

/*@
    requires valid_range(a) && valid_range(b) && distinct(a, b);
    ensures result_props(\result, a, b);
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int ans;
    //@ assert valid_range(a) && valid_range(b) && distinct(a, b);
    ans = 6 - a - b;
    //@ assert ans >= 1 && ans <= 3;
    //@ assert ans != a;
    //@ assert ans != b;
    //@ assert ans == 6 - a - b;
    return ans;
}
