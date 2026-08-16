#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100);
    requires (1 <= (w) <= 100);
    ensures ((\result) == ((w) >= (s)));
*/
bool func(int s, int w)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (1 <= (s) <= 100);
    //@ assert (1 <= (w) <= 100);
    //@ assert w >= s ==> w >= s;
    
    result = (w >= s);
    return result;
}
