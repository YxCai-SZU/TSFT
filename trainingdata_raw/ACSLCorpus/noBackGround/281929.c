/*@
    requires (1 <= (n) <= 1000000000 && 1 <= (m) <= 1000000000);
    ensures \result <= n + m / 2;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    unsigned int ans;

    //@ assert m / 2 <= n + m / 2;
    //@ assert n * 2 <= 2 * n;
    //@ assert n + m / 2 <= n + m / 2;

    if (n * 2 > m)
    {
        ans = m / 2;
    }
    else
    {
        ans = n + m / 2;
    }

    //@ assert ans <= n + m / 2;
    return ans;
}
