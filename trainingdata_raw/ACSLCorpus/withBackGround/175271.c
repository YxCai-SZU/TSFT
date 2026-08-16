#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c) =
        a < b && b < c;
*/

/*@
    requires 1 <= a && a <= 9;
    requires 1 <= b && b <= 9;
    requires 1 <= c && c <= 9;
    ensures \result == true <==> a < b && b < c;
*/
bool func(int a, int b, int c)
{
    bool result = false;

    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;

    if (a < b)
    {
        if (b < c)
        {
            result = true;
        }
    }

    //@ assert result == true <==> a < b && b < c;
    return result;
}
