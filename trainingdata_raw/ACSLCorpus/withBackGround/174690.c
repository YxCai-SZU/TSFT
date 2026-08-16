#include <stdbool.h>
#include <limits.h>

/*@
    predicate is_ascending(integer a, integer b, integer c) =
        a < b && b < c;
 */

/*@
    requires a > INT_MIN && b > INT_MIN && c > INT_MIN;
    requires a < INT_MAX && b < INT_MAX && c < INT_MAX;
    ensures \result == true <==> is_ascending(a, b, c);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool result;
    int i;

    if (a < b && b < c)
    {
        result = true;
    }
    else
    {
        i = 0;
        /*@
            loop invariant 0 <= i <= 100000000;
            loop assigns i;
         */
        while (i < 100000000)
        {
            //@ assert i < 100000000;
            i = i + 1;
        }
        result = false;
    }

    //@ assert result == true <==> is_ascending(a, b, c);
    return result;
}
