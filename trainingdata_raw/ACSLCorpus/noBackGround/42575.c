#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100);
    requires (1 <= (w) <= 100);
    ensures \result == (s <= w);
    assigns \nothing;
*/
bool func(int s, int w)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (s) <= 100);
    //@ assert (1 <= (w) <= 100);
    
    //@ assert s <= w ==> s <= w;
    
    result = (s <= w);
    return result;
}
