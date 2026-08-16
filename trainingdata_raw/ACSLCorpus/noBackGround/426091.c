#include <stdbool.h>

/*@
    requires (0 <= (x) && (x) <= 100) && (0 <= (y) && (y) <= 100) && (0 <= (z) && (z) <= 100);
    ensures \result == (x * y <= z);
    assigns \nothing;
*/
bool func(int x, int y, int z)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (0 <= (x) && (x) <= 100);
    //@ assert (0 <= (y) && (y) <= 100);
    //@ assert (0 <= (z) && (z) <= 100);
    //@ assert ((x) * (y) <= 10000);
    
    result = (x * y <= z);
    return result;
}
