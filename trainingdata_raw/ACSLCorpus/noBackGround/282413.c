/*@
    requires (1 <= (a) && (a) <= 3 &&
        1 <= (b) && (b) <= 3 &&
        (a) != (b));
    ensures \result == (6 - (a) - (b));
*/
long func(long a, long b)
{
    long ans = 0;

    //@ assert (1 <= (a) && (a) <= 3 &&         1 <= (b) && (b) <= 3 &&         (a) != (b));

    if (a == 1)
    {
        if (b == 2)
        {
            ans = 3;
        }
        else
        {
            ans = 2;
        }
    }
    else if (a == 2)
    {
        if (b == 1)
        {
            ans = 3;
        }
        else
        {
            ans = 1;
        }
    }
    else
    {
        if (b == 1)
        {
            ans = 2;
        }
        else
        {
            ans = 1;
        }
    }

    //@ assert ans == (6 - (a) - (b));
    return ans;
}
