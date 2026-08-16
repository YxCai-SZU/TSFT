/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures \result == a || \result == b || \result == c;
    ensures \result >= a && \result >= b && \result >= c ==>
                \result == a || \result == b || \result == c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;

    if (a >= b && a >= c)
    {
        ans = a;
    }
    else if (b >= a && b >= c)
    {
        ans = b;
    }
    else
    {
        ans = c;
    }

    //@ assert ans == a || ans == b || ans == c;
    //@ assert ans >= a && ans >= b && ans >= c ==> ans == a || ans == b || ans == c;

    return ans;
}
