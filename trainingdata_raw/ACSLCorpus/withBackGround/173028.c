#include <stdbool.h>

/*@
    predicate in_range(integer a, integer b, integer c, integer d, integer e, integer k) =
        0 <= a && a < b && b < c && c < d && d < e && e < 124 &&
        0 <= k && k <= 123;

    predicate condition(integer a, integer e, integer k) =
        k >= (e - a) || (e - a - k) <= 1;
*/

/*@
    requires in_range(a, b, c, d, e, k);
    ensures \result == true <==> condition(a, e, k);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    bool result;
    
    //@ assert in_range(a, b, c, d, e, k);
    
    if (k >= (e - a))
    {
        result = true;
    }
    else if ((e - a - k) <= 1)
    {
        result = true;
    }
    else
    {
        //@ assert e - a - k >= 2;
        result = false;
    }

    //@ assert result == true <==> condition(a, e, k);
    return result;
}
