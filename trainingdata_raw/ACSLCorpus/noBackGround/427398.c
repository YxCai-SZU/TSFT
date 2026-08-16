/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result >= 10 && \result <= 999;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max_val;
    int ans;

    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);

    if (a > b)
    {
        if (a > c)
        {
            max_val = a;
        }
        else
        {
            max_val = c;
        }
    }
    else
    {
        if (b > c)
        {
            max_val = b;
        }
        else
        {
            max_val = c;
        }
    }

    //@ assert max_val == a || max_val == b || max_val == c;
    //@ assert (1 <= (max_val) <= 9);

    ans = max_val * 10 + max_val + max_val;

    //@ assert ans == max_val * 10 + max_val + max_val;
    //@ assert ans >= 10 && ans <= 999;

    return ans;
}
