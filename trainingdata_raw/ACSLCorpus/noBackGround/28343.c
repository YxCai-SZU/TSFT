/*@
    requires (1 <= (x) && (x) <= 100 &&
        1 <= (y) && (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == ((x) + (y) / 2);
    assigns \nothing;
*/
int func(int x, int y)
{
    int result;
    int temp_y;
    int count;
    int is_even;

    result = x;
    temp_y = y;
    count = 0;
    is_even = 0;

    /*@
        loop invariant 0 <= temp_y && temp_y <= y;
        loop invariant 0 <= count && count <= y / 2;
        loop invariant temp_y == y - 2 * count;
        loop assigns temp_y, count;
    */
    while (temp_y >= 2)
    {
        temp_y -= 2;
        count += 1;
    }

    //@ assert temp_y == 0;
    if (temp_y == 0)
    {
        is_even = 1;
    }

    //@ assert is_even == 1;
    if (is_even)
    {
        result += count;
    }

    //@ assert result == x + y / 2;
    return result;
}
