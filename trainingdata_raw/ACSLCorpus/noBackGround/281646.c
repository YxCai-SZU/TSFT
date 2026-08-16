#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 15);
    requires (0 <= (b) && (b) <= 15);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert (0 <= (a) && (a) <= 15);
    //@ assert (0 <= (b) && (b) <= 15);
    
    //@ assert 0 <= ((a) * (b)) && ((a) * (b)) <= 225;
    
    result = a * b;
    
    //@ assert result == ((a) * (b));
    
    return result;
}
