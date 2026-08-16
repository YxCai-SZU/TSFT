#include <stdint.h>

/*@
    requires (2 <= (a) <= 100) && (2 <= (b) <= 100);
    ensures ((\result) == ((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert b - 1 <= 99;
    //@ assert 1 <= a - 1;
    //@ assert (a - 1) * (b - 1) <= 99 * 99;
    
    result = (a - 1) * (b - 1);
    
    //@ assert result == (a - 1) * (b - 1);
    return result;
}
