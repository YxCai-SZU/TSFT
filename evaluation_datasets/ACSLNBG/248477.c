#include <stdint.h>


uint32_t func(uint32_t x)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert (1 <= (x) && (x) <= 10);
    
    //@ assert ((x) * (1 + (x) + (x) * (x))) <= 10 * (1 + 10 + 10 * 10);
    
    result = x * (1 + x + x * x);
    
    //@ assert result == ((x) * (1 + (x) + (x) * (x)));
    
    return result;
}
