#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (((n) - 2) * 180);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert (3 <= (n) && (n) <= 100);
    
    //@ assert 1 <= (n - 2) && (n - 2) <= 98;
    
    //@ assert (n - 2) * 180 <= 17640;
    
    //@ assert (n - 2) * 180 >= 180;
    
    result = (int32_t)((n - 2) * 180);
    
    //@ assert result == (((n) - 2) * 180);
    
    return result;
}
