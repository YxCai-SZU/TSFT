#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == (((l) * (l) * (l)) / 27);
    assigns \nothing;
*/
int64_t func(uint64_t l)
{
    uint64_t l_64;
    uint64_t result;
    
    l_64 = l;
    
    //@ assert l_64 >= 1 && l_64 <= 1000;
    
    //@ assert l_64 * l_64 <= 1000 * 1000;
    
    //@ assert l_64 * l_64 * l_64 <= 1000 * 1000 * 1000;
    
    result = l_64 * l_64 * l_64 / 27;
    return (int64_t)result;
}
