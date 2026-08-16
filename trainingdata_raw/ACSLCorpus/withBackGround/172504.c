#include <stdbool.h>

/*@
    predicate condition_holds(integer a, integer b, integer c, integer d) =
        c <= b + d || a <= b + c;
 */

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    requires 1 <= d && d <= 100;
    ensures \result == true <==> (c <= b + d || a <= b + c);
 */
bool func(int a, int b, int c, int d)
{
    bool result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert 1 <= d && d <= 100;

    if (c <= b + d)
    {
        //@ assert c <= b + d;
        result = true;
    }
    else if (a <= b + c)
    {
        //@ assert a <= b + c;
        result = true;
    }
    else
    {
        //@ assert !(c <= b + d) && !(a <= b + c);
        result = false;
    }

    //@ assert result == true <==> (c <= b + d || a <= b + c);
    return result;
}
