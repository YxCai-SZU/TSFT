/*@
    requires ((x) >= 1 && (x) <= 100 &&
        (y) >= 1 && (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result >= 0;
    ensures \result == x + ((y) / 2);
*/
long func(long x, long y)
{
    long half_y;
    long count;
    long temp_y;

    if (y >= 0)
    {
        count = 0;
        temp_y = y;
        /*@
            loop invariant temp_y >= 0;
            loop invariant temp_y <= y;
            loop invariant count >= 0;
            loop invariant temp_y == y - 2 * count;
            loop assigns temp_y, count;
        */
        while (temp_y >= 2)
        {
            temp_y -= 2;
            count += 1;
        }
        half_y = count;
    }
    else
    {
        count = 0;
        temp_y = y;
        /*@
            loop invariant temp_y <= 0;
            loop invariant temp_y >= y;
            loop invariant count <= 0;
            loop invariant temp_y == y - 2 * count;
            loop assigns temp_y, count;
        */
        while (temp_y <= -2)
        {
            temp_y += 2;
            count -= 1;
        }
        half_y = count;
    }

    //@ assert half_y == ((y) / 2);
    long ans = x + half_y;
    //@ assert ans >= 0;
    //@ assert ans == x + ((y) / 2);
    return ans;
}
