#include <stdint.h>

/*@
    predicate valid_params(integer N, integer A) =
        1 <= N <= 10000 && 0 <= A <= 1000;

    logic integer compute_result(integer N, integer A) =
        (N - A < 0) ? 0 : (N - A);
*/

/*@
    requires valid_params(N, A);
    ensures \result >= 0;
    ensures \result <= N;
    ensures \result == compute_result(N, A);
    ensures \result == N - A || \result == 0;
*/
int32_t func(int32_t N, int32_t A)
{
    int32_t ans;
    
    //@ assert valid_params(N, A);
    
    if (N - A < 0)
    {
        ans = 0;
        //@ assert ans == 0;
    }
    else
    {
        ans = N - A;
        //@ assert ans == N - A;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= N;
    //@ assert ans == N - A || ans == 0;
    
    return ans;
}
