/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 100 &&
        (a) + (b) + (c) >= (k));
    ensures ((\result) >= -(c));
    ensures ((\result) <= (a));
*/
int func(int a, int b, int c, int k)
{
    int ans;
    int rst;
    ans = 0;
    rst = k;

    if (a >= rst)
    {
        ans += rst;
    }
    else
    {
        ans += a;
    }

    rst -= a;

    if (rst > 0)
    {
        rst -= b;
    }
    else
    {
        ans -= rst;
    }

    if (rst > 0)
    {
        ans -= rst;
    }

    //@ assert ans >= -c;
    return ans;
}
