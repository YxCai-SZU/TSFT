#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = -100 <= x <= 100;
    predicate ordered(integer a, integer b, integer c) = a < b && b < c;
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    //@ assert is_in_range(c);
    
    if (a < b && b < c)
    {
        //@ assert ordered(a, b, c);
        return true;
    }
    else
    {
        //@ assert !ordered(a, b, c);
        return false;
    }
}
