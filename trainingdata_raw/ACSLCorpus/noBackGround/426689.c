#include <stdint.h>

/*@ requires (1 <= (N) && (N) <= 100) && (0 <= (A) && (A) <= (N) * (N));
    ensures \result == ((N) * (N) - (A));
    assigns \nothing;
 */
uint64_t func(uint64_t N, uint64_t A) {
    // Variable declarations at scope top
    uint64_t res;
    
    //@ assert N * N <= 10000;
    //@ assert N * N >= A;
    
    res = N * N - A;
    return res;
}
