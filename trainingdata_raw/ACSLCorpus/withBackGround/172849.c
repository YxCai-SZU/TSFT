#include <stddef.h>

/*@
    predicate valid_params(integer N, integer K) =
        1 <= K <= N <= 50;
    
    logic integer expected_result(integer N, integer K) =
        N - K + 1;
*/

/*@
    requires valid_params(N, K);
    assigns \nothing;
    ensures \result == expected_result(N, K);
*/
size_t func(size_t N, size_t K) {
    size_t ans = 0;
    
    ans = N - K + 1;
    
    //@ assert ans == N - K + 1;
    
    return ans;
}
