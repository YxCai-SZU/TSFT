#include <stdint.h>

/*@
    requires (1 <= (N) <= 9);
    ensures \result == ((N) * (N) * (N));
    assigns \nothing;
*/
int64_t func(uint64_t N)
{
    //@ assert (1 <= (N) <= 9);
    
    uint64_t NN;
    int64_t result;
    
    //@ assert N * N <= 81;
    //@ assert N * N * N <= 729;
    
    NN = N * N;
    
    //@ assert NN * N <= 729;
    
    result = (int64_t)NN * (int64_t)N;
    
    //@ assert result == ((N) * (N) * (N));
    return result;
}
