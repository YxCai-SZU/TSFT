#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    ensures ((\result) == (a) * (a));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top
    int64_t ans;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert a * a <= 10000;
    
    ans = a * a;
    
    return ans;
}
