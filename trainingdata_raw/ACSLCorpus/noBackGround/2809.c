#include <limits.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == r * r;
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int res;
    
    //@ assert 1 <= r && r <= 100;
    
    //@ assert r * r <= INT_MAX;
    
    res = r * r;
    
    //@ assert res == r * r;
    
    return res;
}
