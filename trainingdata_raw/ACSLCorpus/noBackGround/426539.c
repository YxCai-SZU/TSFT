/*@
    requires (1 <= (X) <= 100 &&
        1 <= (Y) <= 100 &&
        (Y) % 2 == 0);
    ensures \result == X + ((Y) / 2);
*/
int func(int X, int Y)
{
    int Y_div_2;
    int i;
    int tmp_Y;

    Y_div_2 = 0;
    i = 0;
    tmp_Y = Y;

    /*@
        loop invariant 0 <= i <= ((Y) / 2);
        loop invariant tmp_Y == Y - 2 * i;
        loop invariant tmp_Y >= 0;
        loop assigns i, tmp_Y;
    */
    while (tmp_Y >= 2)
    {
        tmp_Y -= 2;
        i += 1;
    }

    Y_div_2 = i;

    //@ assert Y_div_2 == ((Y) / 2);

    return X + Y_div_2;
}
