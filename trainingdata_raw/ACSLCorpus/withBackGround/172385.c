#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
*/

/*@
    requires valid_range(s) && valid_range(w);
    ensures \result == (w >= s);
    assigns \nothing;
*/
bool func(unsigned int s, unsigned int w)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert valid_range(s);
    //@ assert valid_range(w);
    
    result = (w >= s);
    
    //@ assert result == (w >= s);
    return result;
}
