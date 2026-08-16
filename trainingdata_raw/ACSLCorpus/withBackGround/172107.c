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
uint32_t func(uint32_t N, uint32_t A)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert N * N >= A;
    //@ assert N * N <= 10000;
    
    result = N * N - A;
    return result;
}
