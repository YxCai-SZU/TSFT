/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == x + ((y) / 2);
    assigns \nothing;
*/
int func(int x, int y)
{
    int result;
    int temp_y;
    int count;

    result = x;
    temp_y = y;
    count = 0;

    /*@
        loop invariant 0 <= temp_y <= y;
        loop invariant 0 <= count <= ((y) / 2);
        loop invariant temp_y == y - 2 * count;
        loop invariant (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
        loop assigns temp_y, count;
    */
    while (temp_y >= 2)
    {
        temp_y -= 2;
        count += 1;
    }

    result += count;

    //@ assert result == x + count;
    //@ assert count == ((y) / 2);

    return result;
}
