#include <stdint.h>
/*@
    requires (0 <= (N) && (N) <= 1000000000000000000 &&
        0 <= (M) && (M) <= 1000000000000000000);
    ensures \result <= N + M;
    assigns \nothing;
*/
uint64_t func(uint64_t N, uint64_t M)
{
    uint64_t ans;
    //@ assert (0 <= (N) && (N) <= 1000000000000000000 &&         0 <= (M) && (M) <= 1000000000000000000);
    
    if (N * 2 <= M)
    {
        //@ assert N * 2 <= M;
        //@ assert N * 2 + M <= 18446744073709551615;
        //@ assert (N * 2 + M) / 4 <= 4611686018427387903;
        ans = (N * 2 + M) / 4;
    }
    else
    {
        //@ assert N + M / 2 <= 18446744073709551615;
        //@ assert M / 2 <= 9223372036854775807;
        ans = N + M / 2;
    }
    
    //@ assert ans <= N + M;
    return ans;
}
