#include <stdint.h>

/*@
    predicate valid_params(integer N, integer A) =
        1 <= N <= 100 && 0 <= A <= N * N;
    
    logic integer compute_result(integer N, integer A) =
        N * N - A;
*/

/*@
    requires valid_params(N, A);
    ensures \result == compute_result(N, A);
    assigns \nothing;
*/
int32_t func(int32_t N, int32_t A)
{
    // Variable declarations at scope top
    int32_t res;
    
    // Precondition verification
    //@ assert 1 <= N <= 100;
    //@ assert 0 <= A <= N * N;
    
    // Bound verification for N*N
    //@ assert N * N <= 10000;
    
    // Non-negative result verification
    //@ assert N * N >= A;
    //@ assert N * N - A >= 0;
    
    res = N * N - A;
    
    // Postcondition verification
    //@ assert res == compute_result(N, A);
    
    return res;
}
