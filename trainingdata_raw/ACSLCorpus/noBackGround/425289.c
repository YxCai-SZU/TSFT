#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t ans;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    //@ assert ((a) * (b)) <= 10000;
    
    ans = a * b;
    
    //@ assert ans == ((a) * (b));
    
    return ans;
}
