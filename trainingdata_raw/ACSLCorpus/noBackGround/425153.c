/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures ((\result) >= 0 && ((\result) == (((n)) - ((m)) * 2) || (\result) == 0));
*/
int func(int n, int m)
{
    int result;
    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);
    result = n - m * 2;
    if (result > 0)
    {
        //@ assert result == ((n) - (m) * 2);
        return result;
    }
    else
    {
        //@ assert result <= 0;
        //@ assert result == ((n) - (m) * 2);
        //@ assert ((0) >= 0 && ((0) == (((n)) - ((m)) * 2) || (0) == 0));
        return 0;
    }
}
