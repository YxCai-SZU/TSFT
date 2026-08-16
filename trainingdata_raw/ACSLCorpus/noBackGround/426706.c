#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000);
    requires (1 <= (t) <= 10000);
    requires (1 <= (s) <= 10000);
    ensures \result == (t * s >= d);
*/
bool func(int d, int t, int s)
{
    // Variable declarations
    bool result;
    
    //@ assert t >= 1 && t <= 10000;
    //@ assert s >= 1 && s <= 10000;
    //@ assert t * s >= 1 && t * s <= 100000000;
    
    result = (t * s >= d);
    
    return result;
}
