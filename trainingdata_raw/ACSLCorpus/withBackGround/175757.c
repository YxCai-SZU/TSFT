#include <stdbool.h>

/*@
    predicate is_strictly_increasing(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;
 */

/*@
    requires 1 <= a && a <= 123;
    requires 1 <= b && b <= 123;
    requires 1 <= c && c <= 123;
    requires 1 <= d && d <= 123;
    requires 1 <= e && e <= 123;
    ensures \result == (a < b && b < c && c < d && d < e);
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e)
{
    //@ assert 1 <= a && a <= 123;
    //@ assert 1 <= b && b <= 123;
    //@ assert 1 <= c && c <= 123;
    //@ assert 1 <= d && d <= 123;
    //@ assert 1 <= e && e <= 123;
    
    bool result;
    
    if (a < b && b < c && c < d && d < e)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    //@ assert result == (a < b && b < c && c < d && d < e);
    return result;
}
