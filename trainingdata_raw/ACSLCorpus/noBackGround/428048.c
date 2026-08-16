/*@
    requires (1 <= (n) <= 1000000000000000000 &&
        1 <= (m) <= 1000000000000000000);
    ensures \result <= n + m;
    assigns \nothing;
*/
unsigned long long func(unsigned long long n, unsigned long long m)
{
    unsigned long long ans;
    //@ assert n / 2 <= n;
    //@ assert n / 2 + m <= n + m;
    //@ assert m - (n / 2) <= m;
    
    if (m > n / 2)
    {
        ans = n / 2 + m - n / 2;
    }
    else
    {
        ans = m + m;
    }
    
    return ans;
}

int main(void)
{
    return 0;
}
