/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == 1 <==> (x == 7 || y == 7 || x + y == 7);
    assigns \nothing;
 */
int func(int x, int y)
{
    int ans;
    ans = 0;

    if (x == 7 || y == 7)
    {
        ans = 1;
    }
    else if (x + y == 7)
    {
        ans = 1;
    }

    //@ assert ans == 1 <==> (x == 7 || y == 7 || x + y == 7);
    return ans;
}
