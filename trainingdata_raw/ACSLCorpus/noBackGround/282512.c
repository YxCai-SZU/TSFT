/*@
    requires (1 <= (x) <= 16);
    requires (1 <= (y) <= 16);
    requires x + y <= 16;
    ensures \result == (x <= 8 && y <= 8);
*/
_Bool func(long x, long y)
{
    _Bool x_is_affordable;
    _Bool y_is_affordable;
    _Bool is_affordable;

    x_is_affordable = x <= 8;
    y_is_affordable = y <= 8;

    if (x_is_affordable)
    {
        if (y_is_affordable)
        {
            is_affordable = 1;
        }
        else
        {
            is_affordable = 0;
        }
    }
    else
    {
        is_affordable = 0;
    }

    //@ assert is_affordable == (x <= 8 && y <= 8);

    return is_affordable;
}
