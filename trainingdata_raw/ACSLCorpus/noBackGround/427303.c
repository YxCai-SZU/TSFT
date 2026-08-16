#include <stdint.h>

/*@
    requires 1 <= x <= 1000000000;
    ensures \result == ((x - 1) / 2 + 1) * (x / 2) / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    // Variable declarations at top
    uint64_t term1;
    uint64_t term2;
    uint64_t prod;
    uint64_t result;

    //@ assert x > 0 && x <= 1000000000;
    
    term1 = (x - 1) / 2 + 1;
    //@ assert term1 <= 500000000;
    
    term2 = x / 2;
    //@ assert term2 <= 500000000;
    
    prod = term1 * term2;
    //@ assert prod <= 250000000000000000;
    
    result = prod / 2;
    return result;
}
