#include <stdint.h>

/*@
    requires (1 <= (x) <= 10);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t x_squared;
    
    //@ assert x * x <= 100;
    x_squared = x * x;
    
    //@ assert x_squared * x <= 1000;
    return x_squared * x;
}
