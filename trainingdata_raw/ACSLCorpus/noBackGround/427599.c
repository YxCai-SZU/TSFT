/*@
    requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100) && (-100 <= (c) && (c) <= 100);
    ensures \result >= 0 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans = 0;

    if (a == 0)
    {
        ans += 1;
    }
    if (b == 0)
    {
        ans += 1;
    }
    if (c == 0)
    {
        ans += 1;
    }

    //@ assert ans >= 0;
    //@ assert ans <= 3;

    return ans;
}
