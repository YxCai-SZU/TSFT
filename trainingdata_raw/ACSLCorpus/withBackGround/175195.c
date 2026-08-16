/*@
    predicate is_divisible(integer i, integer d) =
        i % d == 0;

    lemma count_bound:
        \forall integer l, r, d, count, i;
        1 <= l <= r <= 100 && 1 <= d <= 100 &&
        l <= i <= r + 1 && 0 <= count <= i - l ==>
        count <= r - l + 1;
*/

/*@
    requires 1 <= l <= r <= 100;
    requires 1 <= d <= 100;
    ensures \result >= 0;
    ensures \result <= r - l + 1;
    assigns \nothing;
*/
int func(int l, int r, int d)
{
    int count = 0;
    int i = l;

    /*@
        loop invariant l <= i <= r + 1;
        loop invariant 0 <= count <= i - l;
        loop invariant count <= r - l + 1;
        loop assigns i, count;
        loop variant r - i + 1;
    */
    while (i <= r)
    {
        int is_divisible = 0;
        int temp = i;

        /*@
            loop invariant 1 <= d <= 100;
            loop invariant 0 <= temp <= i;
            loop invariant temp <= 100;
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

    //@ assert count >= 0;
    //@ assert count <= r - l + 1;
    return count;
}
