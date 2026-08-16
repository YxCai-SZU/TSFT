#include <stdbool.h>

/*@
    predicate within_range(integer a, integer b, integer c) =
        a <= b ==> (c >= a && c <= b);
*/

/*@
    requires a <= b;
    ensures \result == (c >= a && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    if (c >= a && c <= b)
    {
        //@ assert c >= a && c <= b;
        result = true;
    }
    else
    {
        //@ assert !(c >= a && c <= b);
        result = false;
    }

    return result;
}
