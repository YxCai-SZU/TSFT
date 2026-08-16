#include <limits.h>

/*@
    requires (1 <= (n) <= 9);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int res;
    
    //@ assert (1 <= (n) <= 9);
    
    //@ assert n * n <= INT_MAX / n;
    
    //@ assert n * n * n <= INT_MAX;
    
    res = n * n * n;
    
    //@ assert res == ((n) * (n) * (n));
    
    return res;
}
