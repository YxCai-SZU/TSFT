#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) * 50 + (a) * 10);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert a * 50 <= 500;
    //@ assert a * 10 <= 100;
    //@ assert a * 50 + a * 10 <= 600;
    
    result = (int32_t)(a * 50 + a * 10);
    return result;
}
