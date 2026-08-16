#include <stdint.h>

/*@
    requires (1 <= (N) <= 100 && 0 <= (A) <= (N) * (N));
    ensures \result == N * N - A;
    assigns \nothing;
*/
int32_t func(int32_t N, int32_t A) {
    int32_t result;
    
    //@ assert N * N >= A;
    //@ assert N * N <= 10000;
    
    result = N * N - A;
    return result;
}
