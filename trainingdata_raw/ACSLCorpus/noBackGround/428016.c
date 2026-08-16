#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100);
    requires (1 <= (w) <= 100);
    ensures ((\result) == ((s) <= (w)));
*/
bool func(long s, long w)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert s >= 1 && s <= 100;
    //@ assert w >= 1 && w <= 100;
    
    //@ assert s <= w ==> s <= w;
    
    result = s <= w;
    return result;
}
