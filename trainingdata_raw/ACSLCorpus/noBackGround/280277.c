#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (180 * ((n) - 2));
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t ans;
    
    //@ assert (3 <= (n) && (n) <= 100);
    ans = 180 * (n - 2);
    //@ assert ans == (180 * ((n) - 2));
    
    return ans;
}
