#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == true <==> d <= t * s;
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    bool result;
    
    // Precondition assertions
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    
    if (d <= t * s) {
        result = true;
    } else {
        result = false;
    }
    
    // Postcondition verification
    //@ assert result == true <==> d <= t * s;
    
    return result;
}
