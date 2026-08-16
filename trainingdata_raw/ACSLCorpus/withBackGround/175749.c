/*@
    predicate valid_range(integer l, integer r) =
        1 <= l && l <= r && r <= 100;

    predicate valid_divisor(integer d) =
        1 <= d && d <= 100;

    predicate count_bounds(integer count, integer i, integer l) =
        count >= 0 && count <= i - l;
*/

/*@
    requires valid_range(l, r) && valid_divisor(d);
    ensures \result >= 0 && \result <= r - l + 1;
    assigns \nothing;
*/
int func(int l, int r, int d)
{
    int count = 0;
    int i = l;

    /*@
        loop invariant l <= i && i <= r + 1;
        loop invariant count_bounds(count, i, l);
        loop assigns count, i;
        loop variant r - i + 1;
    */
    while (i <= r)
    {
        int is_divisible = 0;
        int temp = i;

        /*@
            loop invariant temp >= 0 && temp <= i;
            loop invariant temp == i - (i - temp);
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= d)
        {
            temp -= d;
        }

        if (temp == 0)
        {
            is_divisible = 1;
        }

        if (is_divisible)
        {
            count += 1;
        }

        i += 1;
    }

    return count;
}
