/*@
    requires (1 <= (a) && (a) <= 3 &&
        1 <= (b) && (b) <= 3 &&
        (a) != (b));
    ensures ((\result) >= 1 && (\result) <= 6 &&
        (\result) != (a) && (\result) != (b));
*/
int func(int a, int b)
{
    int c;

    c = 0;

    if (a == 1 && b == 2)
    {
        c = 3;
    }
    else if (a == 1 && b == 3)
    {
        c = 2;
    }
    else if (a == 2 && b == 1)
    {
        c = 3;
    }
    else if (a == 2 && b == 3)
    {
        c = 1;
    }
    else if (a == 3 && b == 1)
    {
        c = 2;
    }
    else if (a == 3 && b == 2)
    {
        c = 1;
    }

    //@ assert c >= 1 && c <= 6;
    //@ assert c != a && c != b;

    return c;
}
