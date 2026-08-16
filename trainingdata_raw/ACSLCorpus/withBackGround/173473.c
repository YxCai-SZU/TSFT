#include <stdbool.h>

/*@
    predicate is_less(integer a, integer b, integer c, integer d) =
        a < c || (a == c && b < d);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> is_less(a, b, c, d);
*/
bool func(int a, int b, int c, int d)
{
    bool result;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;

    if (a == c)
    {
        if (b < d)
        {
            //@ assert is_less(a, b, c, d);
            result = true;
        }
        else
        {
            //@ assert !is_less(a, b, c, d);
            result = false;
        }
    }
    else if (a < c)
    {
        //@ assert is_less(a, b, c, d);
        result = true;
    }
    else
    {
        //@ assert !is_less(a, b, c, d);
        result = false;
    }

    return result;
}
