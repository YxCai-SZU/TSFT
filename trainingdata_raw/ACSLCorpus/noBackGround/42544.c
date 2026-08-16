#include <stdint.h>

/*@ requires (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    ensures \result == (6 - (a) - (b));
    assigns \nothing;
 */
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    
    result = 6;
    //@ assert result == 6;
    
    result -= a;
    //@ assert result == 6 - a;
    
    result -= b;
    //@ assert result == (6 - (a) - (b));
    
    return (int32_t)result;
}
