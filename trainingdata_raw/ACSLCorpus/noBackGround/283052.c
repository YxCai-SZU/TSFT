/*@
    requires 3 <= a <= 20;
    requires 3 <= b <= 20;
    ensures \result >= 0;
    ensures \result == a - 1 || \result == a || \result == a + 1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;

    //@ assert a >= 3 && a <= 20;
    //@ assert b >= 3 && b <= 20;

    if (a > b + 1)
    {
        result = a - 1;
    }
    else if (a == b + 1)
    {
        result = a;
    }
    else
    {
        result = a + 1;
    }

    //@ assert result >= 0;
    //@ assert result == a - 1 || result == a || result == a + 1;
    return result;
}
