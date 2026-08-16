/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result >= 0;
    ensures \result == (((a) == (b)) ? ((a) + (b) - 1) : (((a) > (b)) ? ((a) + (b) - 1) : ((a) + (b))));
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    int i;
    int j;

    result = 0;
    i = 0;
    j = 0;

    if (a > b)
    {
        i = a;
        j = b;
    }
    else
    {
        i = b;
        j = a;
    }

    result = i + j;

    if (a == b)
    {
        result = result - 1;
    }

    if (a > b)
    {
        result = result - 1;
    }

    //@ assert result >= 0;

    return result;
}
