#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 9);
    ensures \result == (((k) * 2) >= 9);
    assigns \nothing;
*/
bool func(unsigned int k)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (1 <= (k) && (k) <= 9);
    
    //@ assert ((k) * 2) <= 18;
    
    result = (k * 2) >= 9;
    
    return result;
}
