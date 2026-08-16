#include <limits.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int ans;
    
    //@ assert (1 <= (r) <= 100);
    
    //@ assert 3 * r >= 3 * 1;
    //@ assert 3 * r <= 3 * 100;
    
    //@ assert (3 * r) * r <= INT_MAX;
    //@ assert (3 * r) * r >= INT_MIN;
    
    ans = 3 * r * r;
    
    //@ assert ans == (3 * (r) * (r));
    return ans;
}
