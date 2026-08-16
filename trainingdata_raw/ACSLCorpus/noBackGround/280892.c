/*@
    requires (((a) == 1 && (b) == 2) || ((a) == 2 && (b) == 1) ||
        ((a) == 1 && (b) == 3) || ((a) == 3 && (b) == 1) ||
        ((a) == 2 && (b) == 3) || ((a) == 3 && (b) == 2));
    ensures \result == (6 - (a) - (b));
    ensures \result >= 1;
*/
int func(int a, int b)
{
    int res = 0;

    if (a == 1)
    {
        if (b == 2)
        {
            res = 3;
        }
        else if (b == 3)
        {
            res = 2;
        }
    }
    else if (a == 2)
    {
        if (b == 1)
        {
            res = 3;
        }
        else if (b == 3)
        {
            res = 1;
        }
    }
    else if (a == 3)
    {
        if (b == 1)
        {
            res = 2;
        }
        else if (b == 2)
        {
            res = 1;
        }
    }

    //@ assert res == (6 - (a) - (b));
    //@ assert res >= 1;

    return res;
}
