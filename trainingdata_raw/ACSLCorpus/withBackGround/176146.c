#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    ensures \result == (a <= b);
*/
bool func(long a, long b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    
    result = (a <= b);
    return result;
}
