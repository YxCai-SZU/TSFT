/*@
    requires (1 <= (X) <= 100 &&
        1 <= (Y) <= 100 &&
        (Y) % 2 == 0);
    ensures \result == X + ((Y) / 2);
    assigns \nothing;
*/
int func(int X, int Y)
{
    int half_Y;
    int i;
    int temp_Y;

    half_Y = 0;
    i = 0;
    temp_Y = Y;

    /*@
        loop invariant 1 <= X <= 100;
        loop invariant 1 <= Y <= 100;
        loop invariant Y % 2 == 0;
        loop invariant 0 <= temp_Y <= Y;
        loop invariant 0 <= half_Y <= ((Y) / 2);
        loop invariant temp_Y == Y - 2 * half_Y;
        loop invariant i == half_Y;
        loop assigns temp_Y, half_Y, i;
        loop variant temp_Y;
    */
    while (temp_Y >= 2)
    {
        temp_Y -= 2;
        half_Y += 1;
        i += 1;
    }

    //@ assert half_Y == ((Y) / 2);
    return X + half_Y;
}
