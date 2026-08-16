/*@
    requires 1 <= X && X <= 100;
    requires 1 <= Y && Y <= 100;
    ensures ((\result) >= 0);
    ensures ((\result) == (X) - (Y) * 2 || (\result) == 0);
*/
int func(int X, int Y)
{
    int ans;

    ans = X - Y * 2;
    if (ans > 0)
    {
        //@ assert ans == X - Y * 2;
        return ans;
    }
    else
    {
        return 0;
    }
}
