#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == true <==> (x + y >= 10 || (y % 2 == 0 && y != 0));
    assigns \nothing;
 */
bool func(unsigned int x, unsigned int y)
{
    bool ok = false;
    
    if (x + y >= 10) {
        ok = true;
    } else if (y % 2 == 0 && y != 0) {
        ok = true;
    }
    
    //@ assert ok == true <==> (x + y >= 10 || (y % 2 == 0 && y != 0));
    
    return ok;
}
