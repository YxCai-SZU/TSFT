/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures (n <= 9 && m <= 9) ==> \result == n * m;
    ensures (n > 9 || m > 9) ==> \result == -1;
*/
int func(int n, int m)
{
    int result;
    //@ assert 1 <= n <= 20 && 1 <= m <= 20;
    
    if (n <= 9 && m <= 9)
    {
        //@ assert (1 <= (n) <= 9 && 1 <= (m) <= 9);
        //@ assert n * m >= 1 * 1 && n * m <= 9 * 9;
        result = n * m;
        //@ assert result == ((n) * (m));
    }
    else
    {
        //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20 && ((n) > 9 || (m) > 9));
        //@ assert n * m >= -20 * 20 && n * m <= 20 * 20;
        //@ assert n > 9 || m > 9;
        result = -1;
    }
    
    return result;
}
