#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100) && (1 <= (w) <= 100);
    ensures \result == (s <= w);
    assigns \nothing;
*/
bool func(unsigned int s, unsigned int w)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (1 <= (s) <= 100);
    //@ assert (1 <= (w) <= 100);
    
    result = (s <= w);
    
    //@ assert result == (s <= w);
    return result;
}
