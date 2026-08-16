/*@
    requires ((n) >= 1) && ((m) >= 1);
    requires ((n) <= 1000000000000) && ((m) <= 1000000000000);
    ensures ((\result) >= 0);
    ensures \result <= n + m;
    assigns \nothing;
*/
unsigned long long func(unsigned long long n, unsigned long long m)
{
    unsigned long long n_local;
    unsigned long long ans;

    //@ assert n <= 1000000000000;
    //@ assert m <= 1000000000000;
    
    if (n > 2 * m)
    {
        n_local = 2 * m;
    }
    else
    {
        n_local = n;
    }
    
    //@ assert n_local <= 2 * m;
    //@ assert m - n_local / 2 <= n + m;
    
    ans = m - n_local / 2;
    
    return ans;
}
