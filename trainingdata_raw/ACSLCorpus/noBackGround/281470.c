/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    int tmp;

    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert 2 * b <= 200;

    tmp = 2 * b;
    ans = a - tmp;

    if (ans < 0)
    {
        ans = 0;
    }

    //@ assert ans >= 0;
    //@ assert ans <= a;
    return ans;
}
