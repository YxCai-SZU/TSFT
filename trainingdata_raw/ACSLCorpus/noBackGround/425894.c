#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100 && 2 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b) - ((a) + (b) - 1));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t x;
    uint32_t y;
    int32_t result;

    //@ assert (2 <= (a) && (a) <= 100 && 2 <= (b) && (b) <= 100);
    
    //@ assert a * b <= 10000;
    
    //@ assert a + b - 1 <= 199;
    
    x = a * b;
    y = a + b - 1;
    
    //@ assert x >= y;
    
    result = (int32_t)(x - y);
    
    //@ assert result == ((a) * (b) - ((a) + (b) - 1));
    
    return result;
}
