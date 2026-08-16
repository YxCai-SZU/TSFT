#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c) =
        a < b && b < c;
 */

/*@
    requires a <= 1000 && b <= 1000 && c <= 1000;
    ensures \result == true <==> (a < b && b < c);
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert a <= 1000 && b <= 1000 && c <= 1000;
    
    if (a < b && b < c)
    {
        //@ assert a < b && b < c;
        return true;
    }
    else
    {
        //@ assert !(a < b && b < c);
        return false;
    }
}
