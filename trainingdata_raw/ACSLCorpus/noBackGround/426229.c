/*@
    requires (1 <= (n) && 1 <= (m) && (n) <= 1000000000000 && (m) <= 1000000000000);
    ensures \result <= n + m / 2;
    assigns \nothing;
*/
unsigned long long func(unsigned long long n, unsigned long long m)
{
    unsigned long long ans;
    
    if (n * 2 <= m)
    {
        ans = n + (m - n * 2) / 4;
        //@ assert ans == n + (m - n * 2) / 4;
    }
    else
    {
        ans = m / 2;
        //@ assert ans == m / 2;
    }
    
    //@ assert ans <= n + m / 2;
    return ans;
}
