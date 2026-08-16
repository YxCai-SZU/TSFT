#include <stdint.h>

/*@
    predicate valid_params(integer N, integer K) =
        1 <= N <= 100 && 1 <= K <= 100;

    logic integer func_result(integer N, integer K) =
        (N / K == 1) ? 0 : N - (N / K);

    lemma result_bounds:
        \forall integer N, K;
        valid_params(N, K) ==>
            0 <= func_result(N, K) <= N;

    lemma result_cases:
        \forall integer N, K;
        valid_params(N, K) ==>
            func_result(N, K) == N - (N / K) || func_result(N, K) == 0;
*/

/*@
    requires valid_params(N, K);
    ensures \result >= 0;
    ensures \result <= (int)N;
    ensures \result == (int)N - (int)(N / K) || \result == 0;
    assigns \nothing;
*/
int func(unsigned int N, unsigned int K)
{
    int result;
    unsigned int div_result;

    //@ assert valid_params(N, K);
    div_result = N / K;

    if (div_result == 1)
    {
        //@ assert div_result == 1;
        result = 0;
    }
    else
    {
        //@ assert div_result != 1;
        //@ assert N <= 100;
        //@ assert K <= 100;
        //@ assert div_result <= 100;
        //@ assert (int)N >= (int)div_result;
        result = (int)N - (int)div_result;
    }

    //@ assert result >= 0;
    //@ assert result <= (int)N;
    //@ assert result == (int)N - (int)(N / K) || result == 0;
    return result;
}
