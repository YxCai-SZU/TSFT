#include <stdint.h>

/*@
    predicate valid_params(integer N, integer A) =
        1 <= N <= 100 && 0 <= A <= N * N;
    
    logic integer square(integer N) = N * N;
    
    lemma square_bound: \forall integer N; 1 <= N <= 100 ==> N * N <= 10000;
*/

/*@
    requires valid_params(N, A);
    ensures \result == N * N - A;
    assigns \nothing;
*/
uint64_t func(uint64_t N, uint64_t A) {
    // Variable declarations at scope top
    uint64_t result;
    
    //@ assert 1 <= N <= 100;
    //@ assert 0 <= A <= N * N;
    //@ assert N * N <= 10000;
    
    result = N * N - A;
    return result;
}
