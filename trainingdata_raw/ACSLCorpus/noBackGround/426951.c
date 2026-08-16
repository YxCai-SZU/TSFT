#include <stdint.h>

/*@
    requires (1 <= (N) <= 100 && 0 <= (A) <= (N) * (N));
    ensures \result == ((N) * (N) - (A));
    assigns \nothing;
*/
uint32_t func(uint32_t N, uint32_t A)
{
    // Variable declarations at scope top
    uint32_t res;

    //@ assert 1 <= N <= 100;
    //@ assert 0 <= A <= N * N;
    
    //@ assert N * N <= 10000;
    //@ assert N * N - A <= 10000;

    res = N * N - A;
    return res;
}
