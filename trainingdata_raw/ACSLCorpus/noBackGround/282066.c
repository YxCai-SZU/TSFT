#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (180 * (n) - 360);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at scope top
    int32_t ans;
    
    //@ assert (3 <= (n) && (n) <= 100);
    
    // Proof assertions
    //@ assert 180 * 3 <= 180 * n;
    //@ assert 180 * n <= 180 * 100;
    
    ans = 180 * (int32_t)n - 360;
    
    //@ assert ans == (180 * (n) - 360);
    return ans;
}
