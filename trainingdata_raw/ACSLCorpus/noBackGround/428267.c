/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20);
    ensures \result >= 0 && \result <= n;
    ensures \result == 0 || \result == 1 || \result == n - m;
*/
int func(int n, int m)
{
    int min_val;
    int result;

    //@ assert (1 <= (n) <= 20) && (1 <= (m) <= 20);

    if (n < m)
    {
        min_val = n;
    }
    else
    {
        min_val = m;
    }

    result = n - min_val;

    if (result < 0)
    {
        //@ assert result == 0;
        return 0;
    }
    else if (result == 0)
    {
        return 0;
    }
    else
    {
        //@ assert result >= 0;
        //@ assert result <= n;
        //@ assert result == n - min_val;
        //@ assert result == 1 || result == n - m;
        return result;
    }
}
