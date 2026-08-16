/*@
    requires 1 <= l <= r <= 100;
    requires 1 <= d <= 100;
    ensures \result >= 0;
    ensures \result <= r - l + 1;
*/
int func(int l, int r, int d)
{
    int count;
    int current;
    int is_divisible;
    int temp;

    count = 0;
    current = l;

    /*@
        loop invariant ((1 <= ((l)) && ((l)) <= ((r)) && ((r)) <= 100) &&
        (1 <= ((d)) && ((d)) <= 100) &&
        (l) <= (current) &&
        (current) <= (r) + 1 &&
        0 <= (count) &&
        (count) <= (current) - (l));
        loop assigns current, count, is_divisible, temp;
        loop variant r - current + 1;
    */
    while (current <= r)
    {
        is_divisible = 1;
        temp = current;

        /*@
            loop invariant ((1 <= ((l)) && ((l)) <= ((r)) && ((r)) <= 100) &&
        (1 <= ((d)) && ((d)) <= 100) &&
        (l) <= (current) && (current) <= (r) + 1 &&
        (temp) >= 0 &&
        0 <= (count) &&
        (count) <= (current) - (l) &&
        (temp) <= (current));
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= d)
        {
            temp -= d;
        }

        if (temp != 0)
        {
            is_divisible = 0;
        }

        if (is_divisible)
        {
            count += 1;
        }

        current += 1;
    }

    return count;
}
