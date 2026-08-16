/*@
    requires 1 <= x <= 16;
    requires 1 <= y <= 16;
    requires x + y <= 16;
    ensures \result == 1 <==> (x <= 8 && y <= 8);
*/
int func(long x, long y)
{
    int x_is_within_range;
    int y_is_within_range;
    int result;

    x_is_within_range = (1 <= x && x <= 8);
    y_is_within_range = (1 <= y && y <= 8);

    if (x_is_within_range && y_is_within_range)
    {
        //@ assert ((1 <= ((x)) && ((x)) <= 8) && (1 <= ((y)) && ((y)) <= 8));
        result = 1;
    }
    else
    {
        //@ assert !((1 <= ((x)) && ((x)) <= 8) && (1 <= ((y)) && ((y)) <= 8));
        result = 0;
    }

    return result;
}
