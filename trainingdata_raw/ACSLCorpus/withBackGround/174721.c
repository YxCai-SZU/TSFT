#include <stdbool.h>

/*@
    predicate is_valid_temp(integer x) = -40 <= x <= 40;
*/

/*@
    requires is_valid_temp(x);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert -40 <= x <= 40;
    
    result = (x >= 30);
    
    //@ assert result == (x >= 30);
    
    return result;
}
