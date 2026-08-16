#include <stdint.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100);
    ensures \result == A * B;
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B)
{
    // Variable declarations at top of scope
    int64_t ans;
    
    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert A <= 100;
    //@ assert B <= 100;
    //@ assert ((A) * (B) <= 10000);
    
    ans = A * B;
    return ans;
}
