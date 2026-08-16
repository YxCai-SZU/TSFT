#include <stdint.h>

/*@
    requires (0 <= (a) <= 1);
    ensures \result == a * a;
    ensures \result == a;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert (0 <= (a) <= 1);
    
    result = a * a;
    
    //@ assert result == a * a;
    
    if (a == 0 || a == 1) {
        //@ assert result == a;
    }
    
    //@ assert result == a;
    
    return result;
}
