#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t x;
    uint32_t y;
    uint32_t result;

    //@ assert (1 <= (n) && (n) <= 100);
    
    x = n * 800;
    //@ assert x == n * 800;
    
    y = (n / 15) * 200;
    //@ assert y == (n / 15) * 200;
    
    result = x - y;
    //@ assert result == ((n) * 800 - ((n) / 15) * 200);
    
    return result;
}
