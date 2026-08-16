#include <stdbool.h>

/*@
    predicate is_disjoint(integer a, integer b, integer c, integer d) =
        d < a || b < c;
 */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    requires a <= b;
    requires c <= d;
    ensures \result == (d < a || b < c);
 */
bool func(int a, int b, int c, int d)
{
    bool result;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;
    //@ assert a <= b && c <= d;

    if (d < a || b < c)
    {
        //@ assert d < a || b < c;
        result = true;
    }
    else
    {
        //@ assert !(d < a || b < c);
        result = false;
    }

    //@ assert result == (d < a || b < c);
    return result;
}
