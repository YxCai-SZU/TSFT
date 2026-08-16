#include <stdint.h>

/*@
    predicate valid_input(integer N, integer M) =
        0 <= N && N <= 100 && 0 <= M && M <= N;
    
    logic integer compute_result(integer N, integer M) = N - M;
    
    lemma result_bounds: \forall integer N, M;
        valid_input(N, M) ==> 0 <= compute_result(N, M) && compute_result(N, M) <= N;
*/

/*@
    requires valid_input(N, M);
    ensures \result >= 0;
    ensures \result <= N;
    ensures \result == N - M;
    assigns \nothing;
*/
int64_t func(int64_t N, int64_t M)
{
    int64_t result = 0;
    int64_t temp = N - M;
    
    //@ assert valid_input(N, M);
    
    if (temp > 0)
    {
        result = temp;
    }
    
    //@ assert result == N - M;
    
    return result;
}
