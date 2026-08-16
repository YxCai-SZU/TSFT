#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t sum;
    uint32_t result;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert 3 <= a + b + 1 <= 201;
    
    sum = a + b + 1;
    result = sum / 2;
    
    //@ assert result == (((a) + (b) + 1) / 2);
    return result;
}
