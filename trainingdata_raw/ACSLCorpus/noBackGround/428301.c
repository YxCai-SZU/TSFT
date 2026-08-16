/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100 && 1 <= (k) <= 3);
    ensures \result == a || \result == b || \result == c;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans;
    int i;

    ans = -1;
    i = 0;

    /*@
        loop invariant 0 <= i <= k;
        loop invariant (((i) == 0 && (ans) == -1) || 
        ((i) == 1 && (ans) == (a)) || 
        ((i) == 2 && (ans) == (b)) || 
        ((i) == 3 && (ans) == (c)));
        loop assigns i, ans;
        loop variant k - i;
    */
    while (i < k)
    {
        if (i == 0)
        {
            ans = a;
        }
        else if (i == 1)
        {
            ans = b;
        }
        else if (i == 2)
        {
            ans = c;
        }

        i = i + 1;
    }

    //@ assert ans == a || ans == b || ans == c;
    return ans;
}
