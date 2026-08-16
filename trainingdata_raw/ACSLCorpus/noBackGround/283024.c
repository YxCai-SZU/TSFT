#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 9);
    ensures \result == ((N) * (N) * (N));
    assigns \nothing;
*/
uint64_t func(uint64_t N)
{
    // Variable declarations at scope top
    uint64_t result;
    
    //@ assert (1 <= (N) && (N) <= 9);
    
    //@ assert N * N <= 81;
    //@ assert N * N * N <= 729;
    
    result = N * N * N;
    
    //@ assert result == ((N) * (N) * (N));
    return result;
}
