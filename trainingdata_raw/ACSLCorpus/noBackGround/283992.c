#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 23);
    ensures \result == 48 - (int)N;
    assigns \nothing;
*/
int32_t func(uint32_t N)
{
    int32_t ans;
    //@ assert 1 <= N && N <= 23;
    ans = 48 - (int32_t)N;
    //@ assert ans == 48 - (int)N;
    return ans;
}
