#include <stdbool.h>

/*@
    requires ((x) > 0 && (y) > 0);
    ensures \result == ((x) > (y) ? 1 : 0);
    assigns \nothing;
*/
bool func(int x, int y)
{
    bool result;
    
    //@ assert x > 0;
    //@ assert y > 0;
    
    result = x > y;
    
    //@ assert result == (x > y ? 1 : 0);
    
    return result;
}
