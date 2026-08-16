/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        (k) >= 1 &&
        (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) <= 2000000000);
    ensures (0 <= (\result) && (\result) <= (k));
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans;
    int rst;
    int tmp;

    ans = 0;
    rst = k;

    //@ assert (0 <= (ans) && (ans) <= (k));
    //@ assert (0 <= (rst) && (rst) <= (k));

    // First conditional addition
    if (rst < a)
    {
        tmp = rst;
    }
    else
    {
        tmp = a;
    }
    ans += tmp;
    //@ assert (0 <= (ans) && (ans) <= (k));

    // First conditional subtraction
    if (rst < a)
    {
        tmp = rst;
    }
    else
    {
        tmp = a;
    }
    rst -= tmp;
    //@ assert (0 <= (rst) && (rst) <= (k));

    // Second conditional subtraction
    if (rst < b)
    {
        tmp = rst;
    }
    else
    {
        tmp = b;
    }
    rst -= tmp;
    //@ assert (0 <= (rst) && (rst) <= (k));

    // Final conditional adjustment
    if (rst < 0)
    {
        tmp = -rst;
    }
    else
    {
        tmp = 0;
    }
    ans -= tmp;

    //@ assert (0 <= (ans) && (ans) <= (k));
    return ans;
}
