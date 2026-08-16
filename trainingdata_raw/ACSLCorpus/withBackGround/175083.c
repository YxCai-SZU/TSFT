/*@
    predicate is_in_range(integer l, integer r, integer d) =
        1 <= l && l <= r && r <= 100 && 1 <= d && d <= 100;

    logic integer count_multiple(integer l, integer r, integer d) =
        (r - l + 1) >= 0 ? (r - l + 1) : 0;

    lemma count_non_negative:
        \forall integer l, r, d;
            is_in_range(l, r, d) ==> count_multiple(l, r, d) >= 0;

    lemma count_bound:
        \forall integer l, r, d;
            is_in_range(l, r, d) ==> count_multiple(l, r, d) <= (r - l + 1);
*/

/*@
    requires is_in_range(l, r, d);
    ensures \result >= 0;
    ensures \result <= (r - l + 1);
    assigns \nothing;
*/
int func(int l, int r, int d)
{
    int count = 0;
    int current = l;

    /*@
        loop invariant l <= current <= r + 1;
        loop invariant 0 <= count <= (current - l);
        loop invariant is_in_range(l, r, d);
        loop assigns count, current;
        loop variant r - current + 1;
    */
    while (current <= r)
    {
        int is_multiple = 0;
        int temp = current;

        /*@
            loop invariant 0 <= temp <= current;
            loop invariant current >= l;
            loop invariant is_in_range(l, r, d);
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= d)
        {
            temp -= d;
        }

        if (temp == 0)
        {
            is_multiple = 1;
        }

        if (is_multiple)
        {
            count += 1;
        }

        current += 1;
    }

    //@ assert count >= 0;
    //@ assert count <= (r - l + 1);
    return count;
}
