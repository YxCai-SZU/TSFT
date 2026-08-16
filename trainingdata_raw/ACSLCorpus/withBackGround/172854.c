/*@
    predicate valid_params(integer N, integer K) =
        1 <= N <= 100000 && 1 <= K <= N;

    logic integer compute_result(integer N, integer K) =
        (N - K + 1) / 2 + ((N - K + 1) % 2 != 0 ? 1 : 0);

    lemma result_bounds:
        \forall integer N, K;
        valid_params(N, K) ==>
        1 <= compute_result(N, K) <= N - K + 1;
*/

/*@
    requires valid_params(N, K);
    ensures \result <= N - K + 1;
    ensures \result >= 1;
    assigns \nothing;
*/
unsigned int func(unsigned int N, unsigned int K)
{
    unsigned int result;

    //@ assert valid_params(N, K);
    result = (N - K + 1) / 2;
    
    if ((N - K + 1) % 2 != 0)
    {
        result += 1;
    }

    //@ assert result <= N - K + 1;
    //@ assert result >= 1;
    return result;
}
