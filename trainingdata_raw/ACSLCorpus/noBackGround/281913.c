#include <stdint.h>
/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == ((a) * (1 + (a) + (a) * (a)));
    assigns \nothing;
*/
uint64_t func(uint64_t a)
{
    // Variable declarations at scope top
    uint64_t result;
    
    //@ assert (1 <= (a) && (a) <= 100);
    
    //@ assert 1 + a + a * a <= 1 + 100 + 100 * 100;
    //@ assert a * (1 + a + a * a) <= 100 * (1 + 100 + 100 * 100);
    
    result = a * (1 + a + a * a);
    
    //@ assert result == ((a) * (1 + (a) + (a) * (a)));
    return result;
}
