#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int ans;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert ((r) * (r)) <= 10000;
    
    ans = r * r;
    
    //@ assert ans == ((r) * (r));
    return ans;
}
