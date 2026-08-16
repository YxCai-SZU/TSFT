#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 100);
    ensures \result == (((N) * ((N) - 1)) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t N)
{
    // Variable declarations at scope top
    uint64_t ans;

    //@ assert 1 <= N && N <= 100;
    //@ assert N * (N - 1) <= 100 * 99;
    //@ assert N * (N - 1) >= 0;

    ans = (N * (N - 1)) / 2;
    return ans;
}
