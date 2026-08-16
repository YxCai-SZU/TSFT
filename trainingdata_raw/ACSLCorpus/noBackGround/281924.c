#include <stdint.h>
/*@
    requires (1 <= (N) && (N) <= 1000000000);
    ensures \result == ((N) * ((N) - 1) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t N)
{
    // Variable declarations at scope top
    uint64_t ans;

    //@ assert N > 0 && N <= 1000000000;
    //@ assert N * (N - 1) / 2 <= 9223372036854775807 / 2;
    
    ans = N * (N - 1) / 2;
    return ans;
}
