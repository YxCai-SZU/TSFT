/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures \result >= 1;
    ensures (n == 1 || m == 1) ==> \result == 1;
    ensures (n > 1 && m > 1) ==> \result == (n - 1) * (m - 1);
*/
int func(int n, int m)
{
    int result;

    //@ assert (1 <= (n) <= 20);
    //@ assert (1 <= (m) <= 20);

    if (n == 1 || m == 1)
    {
        result = 1;
        //@ assert result == (((n) == 1 || (m) == 1) ? 1 : ((n) - 1) * ((m) - 1));
    }
    else
    {
        //@ assert n > 1 && m > 1;
        //@ assert 1 <= (n - 1) * (m - 1) <= 19 * 19;
        result = (n - 1) * (m - 1);
        //@ assert result == (((n) == 1 || (m) == 1) ? 1 : ((n) - 1) * ((m) - 1));
    }

    //@ assert result >= 1;
    return result;
}
