#include <stdint.h>

/*@
    requires (1 <= (N) <= 1000000000);
    ensures \result == (((N) - 1) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t N)
{
    uint64_t result;
    
    //@ assert (1 <= (N) <= 1000000000);
    
    result = (N - 1) / 2;
    
    //@ assert result == (((N) - 1) / 2);
    
    return result;
}
