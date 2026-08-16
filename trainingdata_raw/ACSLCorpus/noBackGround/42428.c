/*@
    requires (1 <= (K) && (K) <= (N) && (N) <= 50);
    ensures \result == ((N) - (K) + 1);
    assigns \nothing;
*/
int func(int N, int K)
{
    int result;
    
    //@ assert 1 <= N && N <= 50;
    //@ assert 1 <= K && K <= N;
    //@ assert N - K >= 0;
    //@ assert N - K + 1 <= 51;
    
    result = N - K + 1;
    return result;
}
