#include <stdbool.h>

/*@
 requires (1 <= (d) <= 10000 &&
     1 <= (t) <= 10000 &&
     1 <= (s) <= 10000);
 ensures \result == (t * s >= d);
 assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert ((t) * (s)) >= 1;
    //@ assert ((t) * (s)) <= 100000000;
    
    if (t * s >= d) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
