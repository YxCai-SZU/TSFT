#include <stdint.h>

/*@
    requires (1 <= (N) <= 1000);
    ensures \result == ((N) / 3);
    assigns \nothing;
*/
uint64_t func(uint64_t N)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert (1 <= (N) <= 1000);
    //@ assert ((N) / 3) <= 1000;
    
    result = N / 3;
    return result;
}
