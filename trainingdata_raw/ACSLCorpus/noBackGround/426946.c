/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    assigns \nothing;
    ensures (((m) < 10 ==> (\result) == (n) + (m)) &&
        ((m) >= 10 ==> (\result) == (n) * 2 + ((m) - 10)));
*/
int func(int n, int m)
{
    int result;
    //@ ghost int original_n = n;
    //@ ghost int original_m = m;

    result = 0;

    if (m < 10)
    {
        result = n + m;
        //@ assert result == original_n + original_m;
    }
    else
    {
        //@ assert n * 2 + (m - 10) <= 20 * 2 + (20 - 10);
        result = n * 2 + (m - 10);
        //@ assert result == original_n * 2 + (original_m - 10);
    }

    //@ assert (((original_m) < 10 ==> (result) == (original_n) + (original_m)) &&         ((original_m) >= 10 ==> (result) == (original_n) * 2 + ((original_m) - 10)));
    return result;
}
