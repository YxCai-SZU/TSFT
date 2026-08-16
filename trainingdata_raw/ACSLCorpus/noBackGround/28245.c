#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    ensures \result == (x >= 10);
    assigns \nothing;
*/
bool func(int x)
{
    bool ok = true;
    
    //@ assert 1 <= x <= 100;
    
    if (x < 10) {
        ok = false;
    }
    
    //@ assert ok == (x >= 10);
    
    return ok;
}
