#include <stdint.h>
/*@
    requires 1 <= N <= 1000000000;
    ensures (N % 2 == 0 ==> \result == N) && (N % 2 != 0 ==> \result == 2 * N);
    assigns \nothing;
*/
uint64_t func(uint64_t N)
{
    uint64_t ans;
    //@ ghost uint64_t original_N = N;
    
    if (N % 2 == 0)
    {
        ans = N;
        //@ assert ans == N;
    }
    else
    {
        ans = 2 * N;
        //@ assert ans == 2 * N;
    }
    
    //@ assert (original_N % 2 == 0 ==> ans == original_N) && (original_N % 2 != 0 ==> ans == 2 * original_N);
    return ans;
}
