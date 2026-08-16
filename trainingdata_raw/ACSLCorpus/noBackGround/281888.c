#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    // Variable declarations at top
    bool result;
    
    //@ assert (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    //@ assert t * s <= 10000 * 10000;
    
    if (d <= t * s) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (d <= t * s);
    return result;
}
