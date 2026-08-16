#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 1000000);
    ensures \result == ((n) / 2 + 1);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t res;
    
    //@ assert n / 2 + 1 == n / 2 + 1;
    
    res = n / 2 + 1;
    
    return res;
}
