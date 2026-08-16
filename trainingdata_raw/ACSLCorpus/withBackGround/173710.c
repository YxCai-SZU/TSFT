#include <stdbool.h>
#include <limits.h>

/*@
    predicate is_ordered(integer a, integer b, integer c) =
        a < b && b < c;
 */

/*@
    requires a > INT_MIN && a < INT_MAX;
    requires b > INT_MIN && b < INT_MAX;
    requires c > INT_MIN && c < INT_MAX;
    ensures \result == (a < b && b < c);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool result;

    //@ assert a > INT_MIN && a < INT_MAX;
    //@ assert b > INT_MIN && b < INT_MAX;
    //@ assert c > INT_MIN && c < INT_MAX;

    if (a < b && b < c)
    {
        //@ assert is_ordered(a, b, c);
        result = true;
    }
    else
    {
        //@ assert !is_ordered(a, b, c);
        result = false;
    }

    //@ assert result == (a < b && b < c);
    return result;
}
