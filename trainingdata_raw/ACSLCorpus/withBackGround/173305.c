#include <stdbool.h>
/*@
    predicate lt_max(integer x) = x < 2147483647;
    predicate ordered(integer a, integer b, integer c) = a < b && b < c;
*/
/*@
    requires lt_max(a) && lt_max(b) && lt_max(c);
    ensures \result == true <==> ordered(a, b, c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert lt_max(a);
    //@ assert lt_max(b);
    //@ assert lt_max(c);
    if (a < b)
    {
        if (b < c)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
