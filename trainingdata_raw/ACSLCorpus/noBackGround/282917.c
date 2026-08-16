/*@
    requires (0 <= (n) <= 100 && 0 <= (m) <= 100);
    ensures \result <= n + m / 2;
    ensures \result >= 0;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    unsigned int ans = 0;

    if (n < (m / 2) + (m % 2))
    {
        ans += n;
        unsigned int rem = m - 2 * n;
        ans += (rem / 4) * 2;
        //@ assert ans <= n + m / 2;
    }
    else
    {
        ans = m / 2;
        //@ assert ans <= n + m / 2;
    }

    return ans;
}
