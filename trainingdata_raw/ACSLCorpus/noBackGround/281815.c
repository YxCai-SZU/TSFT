#include <stdint.h>

/*@
    requires (1 <= (N) <= 100 && 1 <= (M) <= 100);
    ensures \result == ((N) * (M) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t N, uint32_t M)
{
    uint32_t result;
    
    //@ assert N * M <= 10000;
    result = N * M / 2;
    
    return result;
}
