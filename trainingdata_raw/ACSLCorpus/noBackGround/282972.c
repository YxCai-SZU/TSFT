/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (a) + (b) + (c) <= 2000000000);
    ensures ((\result) >= -(k) && (\result) <= (k));
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int r;
    int rst;

    r = 0;
    rst = k;

    //@ assert r >= -k && r <= k;
    //@ assert rst >= 0 && rst <= k;

    if (a >= rst)
    {
        r += rst;
        rst -= rst;
    }
    else
    {
        r += a;
        rst -= a;
    }

    //@ assert r >= -k && r <= k;
    //@ assert rst >= 0 && rst <= k;

    if (b >= rst)
    {
        rst -= rst;
    }
    else
    {
        rst -= b;
    }

    //@ assert r >= -k && r <= k;
    //@ assert rst >= 0 && rst <= k;
    //@ assert r - rst >= -k && r - rst <= k;

    r -= rst;

    //@ assert r >= -k && r <= k;

    return r;
}
