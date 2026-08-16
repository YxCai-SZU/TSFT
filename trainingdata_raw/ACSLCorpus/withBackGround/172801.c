#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
*/

/*@
    requires valid_range(s) && valid_range(w);
    ensures \result == (s <= w);
    assigns \nothing;
*/
bool func(unsigned long s, unsigned long w)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= s <= 100;
    //@ assert 1 <= w <= 100;
    
    //@ assert s <= 100 && w <= 100;
    //@ assert s <= w ==> s <= w;
    
    result = s <= w;
    
    //@ assert result == (s <= w);
    return result;
}
