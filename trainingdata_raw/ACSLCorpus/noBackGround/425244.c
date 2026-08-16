/*@
    requires (0 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 1000 &&
        (b) % 2 == 0);
    ensures \result >= 0 && \result <= b;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;

    if (a < 13)
    {
        result = 0;
    }
    else if (a >= 13 && a <= 15)
    {
        result = b / 2;
    }
    else if (a >= 16 && a <= 18)
    {
        result = (2 * (b / 2)) / 3;
    }
    else
    {
        result = b / 2;
    }

    //@ assert result >= 0;
    //@ assert result <= b;

    return result;
}
