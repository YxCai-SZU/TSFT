/*@
    requires (2 <= (N) && (N) <= 100 &&
        2 <= (K) && (K) <= 100);
    ensures \result == (N - 2) * (K - 2) + 1;
    assigns \nothing;
*/
unsigned int func(unsigned int N, unsigned int K)
{
    unsigned int result;
    
    //@ assert 2 <= N && N <= 100;
    //@ assert 2 <= K && K <= 100;
    
    //@ assert N >= 2 && N <= 100;
    //@ assert K >= 2 && K <= 100;
    
    //@ assert (N - 2) * (K - 2) <= 98 * 98;
    //@ assert (N - 2) * (K - 2) >= 0;
    
    result = (N - 2) * (K - 2) + 1;
    
    //@ assert result == (N - 2) * (K - 2) + 1;
    
    return result;
}
