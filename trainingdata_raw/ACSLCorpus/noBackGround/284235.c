/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == x + y / 2;
    assigns \nothing;
*/
int func(int x, int y)
{
    int half_y = 0;
    int i = 0;

    /*@
        loop invariant (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
        loop invariant half_y * 2 == i;
        loop invariant i <= y;
        loop assigns half_y, i;
    */
    while (i < y)
    {
        //@ assert half_y * 2 == i;
        half_y += 1;
        i += 2;
        //@ assert half_y * 2 == i;
    }

    //@ assert half_y == y / 2;
    return x + half_y;
}
