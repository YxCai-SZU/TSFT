#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 10000);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == ((1000 - ((N) % 1000)) % 1000);
*/
int64_t func(int64_t N)
{
    uint64_t N_unsigned;
    uint64_t remainder;
    uint64_t result;
    
    //@ assert (1 <= (N) && (N) <= 10000);
    
    if (N < 0) {
        N_unsigned = (uint64_t)(-N);
    } else {
        N_unsigned = (uint64_t)N;
    }
    
    remainder = N_unsigned % 1000;
    result = (1000 - remainder) % 1000;
    
    //@ assert result == ((1000 - ((N) % 1000)) % 1000);
    
    return (int64_t)result;
}
