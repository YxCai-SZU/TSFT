#include <stdbool.h>
#include <limits.h>

/*@
    predicate strictly_increasing(integer a, integer b, integer c, integer d) =
        a < b && b < c && c < d;
*/

/*@
    requires a <= UINT_MAX;
    requires b <= UINT_MAX;
    requires c <= UINT_MAX;
    requires d <= UINT_MAX;
    ensures \result == true <==> strictly_increasing(a, b, c, d);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result;
    //@ assert a <= UINT_MAX;
    //@ assert b <= UINT_MAX;
    //@ assert c <= UINT_MAX;
    //@ assert d <= UINT_MAX;

    if (a < b && b < c && c < d)
    {
        //@ assert strictly_increasing(a, b, c, d);
        result = true;
    }
    else
    {
        //@ assert !strictly_increasing(a, b, c, d);
        result = false;
    }

    //@ assert result == true <==> strictly_increasing(a, b, c, d);
    return result;
}
