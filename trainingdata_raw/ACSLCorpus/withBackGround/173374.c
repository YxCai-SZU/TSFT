/*@
    predicate is_valid_params(integer N, integer M) =
        1 <= N && N <= 100 && 0 <= M && M <= N;

    logic integer subtraction(integer N, integer M) = N - M;

    lemma subtraction_lemma: \forall integer N, M; 
        is_valid_params(N, M) ==> subtraction(N, M) == N - M;
*/

/*@
    requires is_valid_params(N, M);
    ensures \result == subtraction(N, M);
    assigns \nothing;
*/
unsigned int func(unsigned int N, unsigned int M)
{
    unsigned int answer;

    //@ assert N >= M;
    answer = N - M;
    //@ assert answer == subtraction(N, M);
    return answer;
}
