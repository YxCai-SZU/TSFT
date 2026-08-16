/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result == a + (b / 2);
    assigns \nothing;
*/
int func(int a, int b)
{
    int half_b;
    int count;
    int temp_b;

    if (b >= 0)
    {
        count = 0;
        temp_b = b;
        /*@
            loop invariant 0 <= temp_b <= b;
            loop invariant 0 <= count <= b / 2;
            loop invariant temp_b == b - 2 * count;
            loop assigns temp_b, count;
            loop variant temp_b;
        */
        while (temp_b >= 2)
        {
            temp_b -= 2;
            count += 1;
        }
        half_b = count;
    }
    else
    {
        count = 0;
        temp_b = b;
        /*@
            loop invariant b <= temp_b <= 0;
            loop invariant -b / 2 <= count <= 0;
            loop invariant temp_b == b - 2 * count;
            loop assigns temp_b, count;
            loop variant -temp_b;
        */
        while (temp_b <= -2)
        {
            temp_b += 2;
            count -= 1;
        }
        half_b = count;
    }

    //@ assert half_b == b / 2;

    return a + half_b;
}
