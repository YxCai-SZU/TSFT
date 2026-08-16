#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (int)(a * b + 1) || \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t product;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    
    product = a * b;
    
    if (product < 1000000000U)
    {
        //@ assert product == ((a) * (b));
        return (int32_t)(product + 1U);
    }
    else
    {
        return -1;
    }
}
