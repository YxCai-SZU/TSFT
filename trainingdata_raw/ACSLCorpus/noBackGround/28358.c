/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures ((\result) >= 0 &&
        (\result) <= (c) &&
        ((a) - (b) >= (c) ==> (\result) == 0) &&
        ((a) - (b) < (c) ==> (\result) == (c) - ((a) - (b))));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    int tmp;

    ans = a - b;

    //@ assert ans == a - b;

    // min(c, ans)
    if (c < ans)
    {
        tmp = c;
    }
    else
    {
        tmp = ans;
    }
    ans = tmp;

    // abs(ans)
    if (ans < 0)
    {
        tmp = -ans;
    }
    else
    {
        tmp = ans;
    }
    ans = tmp;

    //@ assert ans == (c < a - b ? c : a - b);
    //@ assert ans >= 0;

    ans = c - ans;

    return ans;
}
