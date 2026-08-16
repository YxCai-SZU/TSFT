#include <stdint.h>

/*@
    requires (1 <= (k) && (k) <= 200);
    ensures \result == ((k) * (k) * (k));
    assigns \nothing;
*/
uint32_t func(uint32_t k)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert (1 <= (k) && (k) <= 200);
    
    //@ assert k * k <= 200 * 200;
    
    //@ assert k * k * k <= 200 * 200 * 200;
    
    result = k * k * k;
    
    //@ assert result == ((k) * (k) * (k));
    
    return result;
}
