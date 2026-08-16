#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert t > 0 && t <= 10000;
    //@ assert s > 0 && s <= 10000;
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    
    // Prevent overflow
    //@ assert (long long)t * (long long)s <= (long long)10000 * (long long)10000;
    
    // Prevent underflow
    //@ assert (long long)t * (long long)s >= 1;
    
    // Ensure no overflow/underflow in the expression t * s >= d
    //@ assert t * s >= 1;
    //@ assert t * s <= 10000 * 10000;
    
    result = (t * s >= d);
    return result;
}
