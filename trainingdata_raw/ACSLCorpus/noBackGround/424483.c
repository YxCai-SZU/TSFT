#include <stdint.h>

/*@
    requires (1 <= (N) <= 100 &&
        0 <= (A) <= (N) * (N));
    ensures \result == ((N) * (N) - (A));
    assigns \nothing;
*/
int32_t func(int32_t N, int32_t A) {
    // Variable declarations at scope top
    int32_t result;
    
    // Verification properties
    //@ assert N * N <= 10000;
    //@ assert N * N >= A;
    
    result = N * N - A;
    return result;
}
