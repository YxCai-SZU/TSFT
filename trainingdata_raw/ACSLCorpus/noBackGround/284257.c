#include <stdint.h>

/*@
    requires 1 <= n <= 10000;
    ensures \result == ((1000 - (((n)) % (1000))) % 1000);
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    uint32_t n_unsigned;
    uint32_t result;
    
    n_unsigned = (uint32_t)n;
    result = (1000 - n_unsigned % 1000) % 1000;
    
    //@ assert result == (1000 - n_unsigned % 1000) % 1000;
    
    return (int32_t)result;
}
