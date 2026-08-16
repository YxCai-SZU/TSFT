/*@
    requires (1 <= (l) <= (r) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0;
    ensures \result <= ((r) - (l) + 1);
    assigns \nothing;
*/
long func(long l, long r, long d)
{
    long count = 0;
    long current = l;

    /*@
        loop invariant l <= current <= r + 1;
        loop invariant count >= 0;
        loop invariant count <= ((current) - (l));
        loop invariant current >= l;
        loop invariant current <= r + 1;
        loop invariant (1 <= (l) <= (r) <= 100);
        loop invariant (1 <= (d) <= 100);
        loop invariant count <= ((r) - (l) + 1);
        loop assigns count, current;
        loop variant r - current + 1;
    */
    while (current <= r)
    {
        char is_multiple = 0;
        long temp = current;

        /*@
            loop invariant temp >= 0;
            loop invariant temp <= current;
            loop invariant (1 <= (d) <= 100);
            loop invariant (1 <= (l) <= (r) <= 100);
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
    //@ assert count <= ((r) - (l) + 1);
    return count;
}
