/*@
    requires (1 <= (N) <= 100 && 1 <= (M) <= 100);
    ensures \result >= 0;
    ensures \result == N - M * 2 || \result == 0;
*/
int func(int N, int M)
{
    int result;
    //@ assert (1 <= (N) <= 100 && 1 <= (M) <= 100);
    result = N - M * 2;
    //@ assert result == ((N) - (M) * 2);
    if (result < 0)
    {
        //@ assert result < 0;
        result = 0;
        //@ assert result == 0;
    }
    //@ assert result >= 0;
    //@ assert result == ((N) - (M) * 2) || result == 0;
    return result;
}
