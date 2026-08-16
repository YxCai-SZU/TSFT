#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * 2 * 3);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t ans;
    
    pi = 3;
    ans = r * 2 * pi;
    
    //@ assert ans == r * 2 * 3;
    
    return ans;
}
