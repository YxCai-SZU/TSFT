/*@
    requires (1 <= (N) && (N) <= 100 && 1 <= (M) && (M) <= 100);
    ensures \result >= 0 && \result <= N;
    assigns \nothing;
*/
int func(int N, int M)
{
    int result;
    //@ ghost int original_N = N;
    //@ ghost int original_M = M;

    result = N - M;
    //@ assert result == original_N - original_M;

    if (result < 0)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        //@ assert result == original_N - original_M;
    }

    //@ assert result >= 0;
    //@ assert result <= original_N;
    return result;
}
