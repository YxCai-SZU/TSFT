#include <stdbool.h>

/*@
    predicate is_in_range(integer t) = -40 <= t && t <= 40;
    predicate is_result(integer t, bool res) = res == (t >= 30);
*/

/*@
    requires is_in_range(t);
    ensures \result == (t >= 30);
    assigns \nothing;
*/
bool func(int t)
{
    // Variable declarations at top of scope
    bool res;
    
    //@ assert -40 <= t && t <= 40;
    
    res = (t >= 30);
    
    //@ assert res == (t >= 30);
    return res;
}
