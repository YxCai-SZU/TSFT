#include <stdint.h>

/*@
    requires (0 <= (k) <= 5);
    ensures \result == (((k) + 1) % 7);
    assigns \nothing;
*/
uint32_t func(uint32_t k)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert (0 <= (k) <= 5);
    
    //@ assert 0 <= (k + 1) % 7 <= 6;
    
    result = (k + 1) % 7;
    
    //@ assert result == (((k) + 1) % 7);
    
    return result;
}
