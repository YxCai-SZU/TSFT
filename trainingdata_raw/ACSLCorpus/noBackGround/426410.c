/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures ((\result) == 0 || (\result) == 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at top of scope
    int result;
    int i;
    int remaining;

    if (m >= n)
    {
        //@ assert m >= n;
        return 1;
    }

    i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant m < n;
        loop assigns i, remaining;
        loop variant n - i;
    */
    while (i < n)
    {
        remaining = n - i;
        if (remaining == m)
        {
            //@ assert remaining == m;
            return 1;
        }
        i = i + 1;
    }

    //@ assert i == n;
    return 0;
}
