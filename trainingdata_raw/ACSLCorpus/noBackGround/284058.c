#include <stdint.h>

/*@
    requires (0 <= (A) <= 10000) && (0 <= (B) <= 10000);
    ensures \result >= 0;
    ensures \result == (A + B) / 2 || \result == (A + B) / 2 + 1;
*/
uint32_t func(uint32_t A, uint32_t B)
{
    uint32_t sum;
    uint32_t avg;
    uint32_t result;
    
    sum = A + B;
    avg = sum / 2;
    
    if (sum % 2 != 0)
    {
        //@ assert sum % 2 != 0;
        result = avg + 1;
    }
    else
    {
        //@ assert sum % 2 == 0;
        result = avg;
    }
    
    return result;
}
