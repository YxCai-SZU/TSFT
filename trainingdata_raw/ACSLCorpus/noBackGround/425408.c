#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (180 * ((n) - 2));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert 3 <= n && n <= 100;
    
    //@ assert n - 2 >= 1 && n - 2 <= 98;
    
    //@ assert 180 * (n - 2) >= 180 && 180 * (n - 2) <= 17640;
    
    result = 180 * ((int32_t)n - 2);
    
    //@ assert result == 180 * ((int32_t)n - 2);
    
    return result;
}
