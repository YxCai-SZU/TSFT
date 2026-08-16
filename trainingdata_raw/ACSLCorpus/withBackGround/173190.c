#include <stdbool.h>

/*@
    predicate valid_inputs(integer N, integer M, integer A) =
        1 <= N && N <= 100 &&
        0 <= M && M <= N &&
        0 <= A && A <= N;

    logic integer func_result(integer N, integer M, integer A) =
        (N == M + A) ? 1 : 0;
*/

/*@
    requires valid_inputs(N, M, A);
    ensures \result == func_result(N, M, A);
    assigns \nothing;
*/
bool func(int N, int M, int A)
{
    bool result;
    
    //@ assert 1 <= N && N <= 100;
    result = (N == M + A);
    
    return result;
}
