#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == (a >= 3);
    assigns \nothing;
*/
bool func(long a)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= a <= 100;
    
    result = (a >= 3);
    
    //@ assert result == (a >= 3);
    return result;
}
