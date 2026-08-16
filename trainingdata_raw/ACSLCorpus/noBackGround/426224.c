/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0);
    requires (1 <= (k) && (k) <= (a) + (b) + (c));
    ensures \result <= k;
*/
int func(int a, int b, int c, int k)
{
    int ans;
    int rst;

    ans = 0;
    rst = k;

    if (a <= rst)
    {
        ans += a;
        rst -= a;
    }
    else
    {
        return k;
    }

    //@ assert ans <= k;

    if (b <= rst)
    {
        rst -= b;
    }
    else
    {
        rst -= rst;
    }

    ans -= rst;

    //@ assert ans <= k;
    return ans;
}
