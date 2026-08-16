#include <limits.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == r * r;
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at scope top
    int ans;
    
    //@ assert r >= 1 && r <= 100;
    //@ assert r * r >= 1 && r * r <= 10000;
    //@ assert r * r <= INT_MAX;
    
    ans = r * r;
    return ans;
}
