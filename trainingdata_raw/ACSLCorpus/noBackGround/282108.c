/*@
    requires (1 <= (x) && (x) <= 100);
    requires (1 <= (y) && (y) <= 100);
    ensures \result == 1 <==> ((y) % 2 == 0 &&
        (((y)) / 2) <= (x) &&
        (x) <= (((y)) / 2) + (((y)) / 2));
 */
int func(int x, int y)
{
    // Variable declarations at the top of the scope
    int result;

    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert (1 <= (y) && (y) <= 100);

    if (y % 2 == 0)
    {
        if ((y / 2) <= x && x <= (y / 2) + (y / 2))
        {
            //@ assert ((y) % 2 == 0 &&         (((y)) / 2) <= (x) &&         (x) <= (((y)) / 2) + (((y)) / 2));
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        result = 0;
    }

    return result;
}
