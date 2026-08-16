#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) * (a) * (a) + (a) * (a) + (a));
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    // Variable declarations at top of scope
    int32_t ans;
    
    //@ assert (1 <= (a) <= 10);
    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;
    //@ assert a * a * a + a * a <= 1100;
    //@ assert a * a * a + a * a + a <= 1110;
    
    ans = a * a * a + a * a + a;
    
    //@ assert ans == ((a) * (a) * (a) + (a) * (a) + (a));
    return ans;
}
