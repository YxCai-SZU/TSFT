/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == a * 2 || \result == a * 2 - 1 || \result == b * 2 - 1;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int result;

    if (a == b)
    {
        result = a * 2;
    }
    else if (a > b)
    {
        //@ assert a > b;
        result = a * 2 - 1;
    }
    else
    {
        //@ assert b > a;
        result = b * 2 - 1;
    }

    return result;
}
