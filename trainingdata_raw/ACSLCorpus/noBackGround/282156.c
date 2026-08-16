/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
*/
int func(int a, int b)
{
    int x;
    int result;

    x = a - 2 * b;
    if (x < 0)
    {
        result = 0;
        //@ assert result >= 0;
        //@ assert result == a - 2 * b || result == 0;
        return result;
    }
    else
    {
        result = x;
        //@ assert result >= 0;
        //@ assert result == a - 2 * b || result == 0;
        return result;
    }
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
*/
int func2(int a, int b)
{
    int x;
    int result;

    x = a - 2 * b;
    if (x < 0)
    {
        //@ assert x < 0;
        result = 0;
        //@ assert result >= 0;
        //@ assert result == a - 2 * b || result == 0;
        return result;
    }
    else
    {
        //@ assert x >= 0;
        result = x;
        //@ assert result >= 0;
        //@ assert result == a - 2 * b || result == 0;
        return result;
    }
}
