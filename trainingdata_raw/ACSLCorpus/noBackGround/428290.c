/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
*/
int func(int a, int b, int c, int d)
{
    int ans = 0;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);

    if (c > a + b + 1)
    {
        ans += c - (a + b + 1);
    }

    if (d > a + b + 1)
    {
        ans += d - (a + b + 1);
    }

    //@ assert ans >= 0;
    //@ assert ans <= a + b + c + d;

    return ans;
}
