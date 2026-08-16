#include <stdint.h>

/*@
    requires (1 <= (x) <= 10);
    ensures \result == ((x) + ((x) * (x)) + ((x) * (x) * (x)));
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    // Variable declarations at top of scope
    int64_t ans;
    
    //@ assert (1 <= (x) <= 10);
    
    //@ assert x * x <= 100;
    //@ assert x * x * x >= 1;
    //@ assert x * x * x <= 1000;
    
    //@ assert x + (x * x) + (x * x * x) >= 3;
    //@ assert x + (x * x) + (x * x * x) <= 1110;
    
    ans = x + (x * x) + (x * x * x);
    
    //@ assert ans == ((x) + ((x) * (x)) + ((x) * (x) * (x)));
    
    return ans;
}
