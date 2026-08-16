#include <stdint.h>

/*@
    requires (1 <= (x) && (x) < 0x1000) && (1 <= (y) && (y) < 0x1000);
    ensures \result == (x * y) / 1000;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations at scope top
    uint32_t product;
    uint32_t result;

    //@ assert (1 <= (x) && (x) < 0x1000);
    //@ assert (1 <= (y) && (y) < 0x1000);
    //@ assert ((x * y) < 0x10000000);
    
    product = x * y;
    result = product / 1000;
    
    return result;
}
