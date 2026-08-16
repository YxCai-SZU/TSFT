/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) <= 2000000000);
    ensures ((\result) >= -(c) && (\result) <= (a));
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans;
    int rst;

    ans = 0;
    rst = k;
    rst -= a;

    if (rst > 0)
    {
        ans += a;
    }
    else
    {
        ans += k;
        //@ assert ((ans) >= -(c) && (ans) <= (a));
        return ans;
    }

    rst -= b;
    if (rst > 0)
    {
        ans -= rst;
    }

    //@ assert ((ans) >= -(c) && (ans) <= (a));
    return ans;
}
