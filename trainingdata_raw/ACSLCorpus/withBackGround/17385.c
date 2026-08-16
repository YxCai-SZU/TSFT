#include <stdbool.h>

/*@
    predicate in_range(integer v) = -100 <= v && v <= 100;
    predicate within_bounds(integer a, integer b, integer c) = 
        a <= b && in_range(a) && in_range(b) && in_range(c);
*/

/*@
    requires within_bounds(a, b, c);
    ensures \result == (c >= a && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert a <= b;

    if (a == b)
    {
        if (c == a)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    else if (a < b)
    {
        if (c >= a && c <= b)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    else
    {
        result = false;
    }

    return result;
}
