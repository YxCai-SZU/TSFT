/*@
    requires ((a) != (b) &&
        ((a) == 1 || (a) == 2 || (a) == 3) &&
        ((b) == 1 || (b) == 2 || (b) == 3));
    ensures \result == 1 || \result == 2 || \result == 3;
    ensures \result != a && \result != b;
*/
int func(int a, int b)
{
    int res;

    if (a == 1 && b == 2)
    {
        res = 3;
    }
    else if (a == 1 && b == 3)
    {
        res = 2;
    }
    else if (a == 2 && b == 1)
    {
        res = 3;
    }
    else if (a == 2 && b == 3)
    {
        res = 1;
    }
    else if (a == 3 && b == 1)
    {
        res = 2;
    }
    else if (a == 3 && b == 2)
    {
        res = 1;
    }
    else
    {
        res = -1;
    }

    //@ assert res == 1 || res == 2 || res == 3;
    //@ assert res != a && res != b;

    return res;
}
