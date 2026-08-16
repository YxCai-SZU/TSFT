#include <stdint.h>

/*@
    requires (0 <= (r) <= 4500 && 0 <= (g) <= 4500);
    ensures \result == (2 * (g) - (r));
    assigns \nothing;
*/
int64_t func(int64_t r, int64_t g)
{
    // Variable declarations at scope top
    int64_t ans;
    
    //@ assert g >= 0 && g <= 4500;
    //@ assert r >= 0 && r <= 4500;
    //@ assert 2 * g <= 9000;
    //@ assert 2 * g - r >= -4500;
    
    ans = 2 * g - r;
    return ans;
}
