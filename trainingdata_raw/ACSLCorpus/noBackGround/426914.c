#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 100);
    requires (0 <= (A) && (A) <= (N) * (N));
    ensures ((\result) == (N) * (N) - (A));
    assigns \nothing;
*/
uint32_t func(uint32_t N, uint32_t A)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert (1 <= (N) && (N) <= 100);
    //@ assert (0 <= (A) && (A) <= (N) * (N));
    
    //@ assert ((N) * (N)) <= 10000;
    //@ assert ((N) * (N) >= (A));
    
    result = N * N - A;
    
    //@ assert ((result) == (N) * (N) - (A));
    return result;
}
