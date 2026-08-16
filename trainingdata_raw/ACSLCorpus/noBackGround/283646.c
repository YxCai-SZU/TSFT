#include <stdint.h>

/*@
    requires 1 <= n <= 10000;
    ensures \result == (((n) % 1000 == 0) ? 0 : 1000 - ((n) % 1000));
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t local_n;
    uint32_t result;
    
    local_n = n % 1000;
    
    if (local_n == 0)
    {
        //@ assert local_n == 0;
        result = 0;
    }
    else
    {
        //@ assert local_n != 0;
        result = 1000 - local_n;
    }
    
    return result;
}
