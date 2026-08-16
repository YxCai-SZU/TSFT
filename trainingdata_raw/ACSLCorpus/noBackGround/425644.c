/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0 && \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    //@ assert 1 <= b && b <= a && a <= 20;
    //@ assert 1 <= c && c <= 20;

    result = c - a + b;

    //@ assert result == ((c) - (a) + (b));
    //@ assert -20 <= result && result <= 40;

    if (result < 0)
    {
        //@ assert result < 0;
        result = 0;
    }
    else
    {
        //@ assert result >= 0;
    }

    //@ assert result >= 0 && result <= c;
    return result;
}
