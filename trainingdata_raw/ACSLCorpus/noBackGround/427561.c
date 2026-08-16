#include <stdbool.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == ((a & 1) == 0);
    assigns \nothing;
*/
bool func(unsigned int a)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a <= 10;
    
    result = ((a & 1) == 0);
    
    return result;
}
