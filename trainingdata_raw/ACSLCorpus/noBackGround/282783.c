#include <stdint.h>

/*@ requires 1 <= a <= 3;
    @ requires 1 <= b <= 3;
    @ requires a != b;
    @ ensures \result == 6 - a - b;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    
    //@ assert (1 <= (a) <= 3 &&       1 <= (b) <= 3 &&       (a) != (b));
    result = 6 - (int32_t)a - (int32_t)b;
    //@ assert result == (6 - (a) - (b));
    return result;
}
