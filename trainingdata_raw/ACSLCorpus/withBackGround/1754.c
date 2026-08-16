#include <stddef.h>

/*@
    predicate valid_params(integer N, integer A) =
        1 <= N <= 100 && 0 <= A <= N * N;
    
    logic integer compute_ans(integer N, integer A) =
        N * N - A;
*/

/*@
    requires valid_params(N, A);
    ensures \result == compute_ans(N, A);
    assigns \nothing;
*/
size_t func(size_t N, size_t A) {
    // Variable declarations at top of scope
    size_t ans;
    
    //@ assert 0 <= N && N <= 100;
    //@ assert 0 <= A && A <= N * N;
    //@ assert N * N <= 10000;
    
    ans = N * N - A;
    return ans;
}
