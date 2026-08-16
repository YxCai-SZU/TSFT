#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c) =
        a < b && b < c;
*/

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> is_ordered(a, b, c);
*/
bool func(int a, int b, int c)
{
    bool result;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    if (a < b)
    {
        if (b < c)
        {
            //@ assert is_ordered(a, b, c);
            result = true;
        }
        else
        {
            //@ assert !is_ordered(a, b, c);
            result = false;
        }
    }
    else
    {
        //@ assert !is_ordered(a, b, c);
        result = false;
    }

    //@ assert result == true <==> is_ordered(a, b, c);
    return result;
}
