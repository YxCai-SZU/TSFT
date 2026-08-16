#include <stdint.h>

/*@
    requires 1 <= n <= 10000;
    ensures (n % 1000 == 0 ==> \result == 0) && 
            (n % 1000 != 0 ==> \result == 1000 - n % 1000);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t result;
    
    if (n % 1000 == 0)
    {
        //@ assert n % 1000 == 0;
        result = 0;
    }
    else
    {
        //@ assert n % 1000 != 0;
        result = 1000 - n % 1000;
    }
    
    return result;
}
