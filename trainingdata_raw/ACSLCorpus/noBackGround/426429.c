#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100 && 1 <= (w) <= 100 && 1 <= (m) <= 100);
    ensures \result == (((s) - (w)) <= m);
    assigns \nothing;
*/
bool func(int s, int w, int m)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= s <= 100;
    //@ assert 1 <= w <= 100;
    //@ assert 1 <= m <= 100;
    
    result = (s - w) <= m;
    
    //@ assert result == (((s) - (w)) <= m);
    return result;
}
