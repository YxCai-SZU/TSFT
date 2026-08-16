#include <stdint.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result == n / 2 + n % 2;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t result = 0;
    
    //@ assert n % 2 == 0 || n % 2 == 1;
    
    if (n % 2 == 1)
    {
        result = 1;
        //@ assert result == 1;
    }
    else
    {
        //@ assert result == 0;
    }
    
    //@ assert result == n % 2;
    
    return n / 2 + result;
}
