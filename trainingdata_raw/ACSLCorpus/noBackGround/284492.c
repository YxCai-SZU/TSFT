/*@
    requires (1 <= (a) && (a) <= 3 &&
        1 <= (b) && (b) <= 3 &&
        (a) != (b));
    ensures ((\result) + (a) + (b) == 6 &&
        1 <= (\result) && (\result) <= 3);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;

    if (a == 1)
    {
        if (b == 2)
        {
            result = 3;
        }
        else
        {
            result = 2;
        }
    }
    else if (a == 2)
    {
        if (b == 1)
        {
            result = 3;
        }
        else
        {
            result = 1;
        }
    }
    else
    {
        if (b == 1)
        {
            result = 2;
        }
        else
        {
            result = 1;
        }
    }

    //@ assert result + a + b == 6;
    //@ assert 1 <= result;
    //@ assert result <= 3;

    return result;
}
