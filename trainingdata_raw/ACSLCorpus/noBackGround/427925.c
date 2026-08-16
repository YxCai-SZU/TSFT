#include <stdbool.h>

/*@
    requires ((0 < ((x)) < 100) && (0 < ((y)) < 100) && (0 < ((z)) < 100));
    ensures \result == (((x) * (y)) < z);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert ((0 < ((x)) < 100) && (0 < ((y)) < 100) && (0 < ((z)) < 100));
    //@ assert ((x) * (y)) < 10000;
    
    result = (x * y) < z;
    return result;
}
