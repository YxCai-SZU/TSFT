#include <stdbool.h>

/*@
    predicate is_positive(integer x) = x > 0;
    predicate ordered(integer a, integer b, integer c) = a < b && b < c;
*/

/*@
    requires is_positive(a) && is_positive(b) && is_positive(c);
    ensures \result == true <==> ordered(a, b, c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    if (a < b && b < c)
    {
        result = true;
    }
    else
    {
        //@ assert is_positive(a);
        //@ assert is_positive(b);
        //@ assert is_positive(c);
        result = false;
    }

    return result;
}
