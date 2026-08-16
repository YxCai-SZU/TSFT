#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) + (b)) * 2 - 1) || \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t product;
    int32_t result;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    sum = a + b;
    //@ assert sum <= 200;
    
    //@ assert sum * 2 <= 400;
    //@ assert sum * 2 - 1 <= 399;
    
    product = sum * 2 - 1;
    result = (int32_t)product;
    
    return result;
}
