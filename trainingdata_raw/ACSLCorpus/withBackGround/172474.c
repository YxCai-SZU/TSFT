#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 0 <= x < 123;
    predicate ordered(integer a, integer b, integer c, integer d, integer e) = 
        a < b && b < c && c < d && d < e;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) && valid_range(e);
    requires 0 <= k <= 123;
    requires ordered(a, b, c, d, e);
    ensures \result == (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert e - a <= k ==> e - a <= k;
    
    result = (e - a <= k);
    return result;
}
