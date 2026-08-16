#include <stdbool.h>

/*@
    predicate condition_holds(integer a, integer b, integer c, integer d) =
        (a > b ==> c > d) && (a <= b ==> d > c);
 */

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == true <==> condition_holds(a, b, c, d);
 */
bool func(long a, long b, long c, long d)
{
    bool result;
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert 1 <= c <= 10000;
    //@ assert 1 <= d <= 10000;
    
    if (a > b)
    {
        result = (c > d);
    }
    else
    {
        result = (d > c);
    }
    
    //@ assert result == true <==> condition_holds(a, b, c, d);
    return result;
}
