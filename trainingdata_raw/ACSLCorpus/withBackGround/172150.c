#include <stdbool.h>

/*@
    predicate condition_holds(integer a, integer b, integer c, integer d) =
        a < c || (a == c && b < d);
 */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> condition_holds(a, b, c, d);
 */
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    //@ assert 1 <= d <= 100;

    if (a < c)
    {
        //@ assert a < c;
        result = true;
    }
    else if (a == c && b < d)
    {
        //@ assert a == c && b < d;
        result = true;
    }
    else
    {
        //@ assert !(a < c || (a == c && b < d));
        result = false;
    }

    //@ assert result == true <==> condition_holds(a, b, c, d);
    return result;
}
