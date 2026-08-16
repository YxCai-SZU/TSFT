#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result <= n;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    uint32_t result;
    
    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    
    if (n > m) {
        result = m;
    } else {
        result = n;
    }
    
    //@ assert result <= n;
    
    return result;
}
