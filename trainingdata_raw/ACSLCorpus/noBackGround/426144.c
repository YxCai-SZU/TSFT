#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100) && (1 <= (y) <= 100) && (1 <= (z) <= 100);
    ensures \result == (x <= z && z <= y + 1);
    assigns \nothing;
*/
bool func(int x, int y, int z)
{
    bool result;
    
    //@ assert (1 <= (x) <= 100);
    
    if (x <= z && z <= (y + 1)) {
        //@ assert x <= z && z <= y + 1;
        result = true;
    } else {
        //@ assert !(x <= z && z <= y + 1);
        result = false;
    }
    
    return result;
}
