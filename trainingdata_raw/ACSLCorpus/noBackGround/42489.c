/*@
    requires (1 <= (N) && (N) <= 100 && 0 <= (A) && (A) <= (N) * (N));
    ensures \result == ((N) * (N) - (A));
*/
int func(int N, int A)
{
    int result;
    
    //@ assert 0 <= N * N - A;
    result = N * N - A;
    
    return result;
}
