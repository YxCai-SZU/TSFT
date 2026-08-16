#include <stdint.h>

/*@
    requires (0 <= (a) && (a) < 24 && 0 <= (b) && (b) < 24);
    ensures \result == (a + b) % 24;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    uint32_t tmp;

    //@ assert (0 <= (a) && (a) < 24 && 0 <= (b) && (b) < 24);
    
    tmp = a + b;
    //@ assert tmp == a + b;
    
    //@ assert tmp == (a + b) % 24 || tmp == a + b;
    
    result = tmp % 24;
    //@ assert result == (a + b) % 24;
    
    return result;
}
