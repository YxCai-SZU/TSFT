#include <stdint.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == ((((x)) * ((x))) * 3);
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    //@ assert (1 <= (x) <= 100);
    
    int32_t x_squared;
    int32_t result;
    
    //@ assert 1 <= x * x <= 10000;
    x_squared = x * x;
    
    //@ assert 3 <= x_squared * 3 <= 30000;
    result = x_squared * 3;
    
    return result;
}
