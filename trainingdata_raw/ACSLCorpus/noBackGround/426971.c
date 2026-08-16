#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == ((n + 999) / 1000) * 1000 - n;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t num;
    uint32_t next_multiple;
    uint32_t result;

    //@ assert (1 <= (n) && (n) <= 10000);
    
    num = (n + 999) / 1000;
    //@ assert num == (((n) + 999) / 1000);
    
    next_multiple = num * 1000;
    //@ assert next_multiple == (((n) + 999) / 1000) * 1000;
    
    result = next_multiple - n;
    //@ assert result == (((n) + 999) / 1000) * 1000 - n;
    
    return result;
}
