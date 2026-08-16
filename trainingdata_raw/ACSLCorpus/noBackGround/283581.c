#include <stdint.h>

/*@
    requires (0 <= (a) <= 0x7FFFFFFF);
    ensures \result == a * a;
    assigns \nothing;
*/
uint64_t func(uint64_t a)
{
    // Variable declarations at scope top
    uint64_t result;
    
    //@ assert (0 <= (a) <= 0x7FFFFFFF);
    
    //@ assert 0 <= a * a <= 0x7FFFFFFF * 0x7FFFFFFF;
    
    result = a * a;
    
    //@ assert result == a * a;
    
    return result;
}
