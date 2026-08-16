#include <stdbool.h>

/*@
    predicate is_between(integer a, integer b, integer c) =
        (a < c && c < b) || (b < c && c < a);
 */

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b && b != c && a != c;
    ensures \result == ((a < c && c < b) || (b < c && c < a));
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert a != b && b != c && a != c;
    if (a < c && c < b)
    {
        //@ assert a < c && c < b;
        return true;
    }
    else if (b < c && c < a)
    {
        //@ assert b < c && c < a;
        return true;
    }
    else
    {
        //@ assert !(a < c && c < b) && !(b < c && c < a);
        return false;
    }
}
