/*@
    requires (2 <= (n) <= 100 && 2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
long func(long n, long m)
{
    long ans;
    //@ assert 1 <= n - 1 <= 99;
    //@ assert 1 <= m - 1 <= 99;
    //@ assert 1 <= (n - 1) * (m - 1) <= 9801;
    ans = (n - 1) * (m - 1);
    return ans;
}
