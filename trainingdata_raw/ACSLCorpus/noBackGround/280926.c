#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 100) && (0 <= (A) && (A) <= (N) * (N));
    ensures ((\result) == (N) * (N) - (A));
    assigns \nothing;
*/
uint32_t func(uint32_t N, uint32_t A)
{
    // Variable declarations at top of scope
    uint32_t N_squared;
    uint32_t result;

    //@ assert N * N <= 10000;
    N_squared = N * N;
    //@ assert N_squared == N * N;
    //@ assert N_squared <= 10000;
    //@ assert N * N >= A;

    result = N_squared - A;
    return result;
}
