/*@
    requires (1 <= (k) <= 200);
    ensures \result == (108 - ((k) / 2) - ((k) % 2));
    assigns \nothing;
*/
int func(int k)
{
    int result;
    int half_k;

    //@ assert (1 <= (k) <= 200);

    if (k % 2 == 0)
    {
        result = 108;
        half_k = k / 2;

        /*@
            loop invariant 0 <= half_k <= k/2;
            loop invariant result == (108 - ((k) / 2) - ((k) % 2)) + half_k;
            loop invariant result >= 0;
            loop assigns result, half_k;
            loop variant half_k;
        */
        while (half_k > 0)
        {
            //@ assert half_k > 0;
            result -= 1;
            half_k -= 1;
            //@ assert result == (108 - ((k) / 2) - ((k) % 2)) + half_k;
        }
        //@ assert half_k == 0;
        //@ assert result == (108 - ((k) / 2) - ((k) % 2));
        return result;
    }
    else
    {
        result = 107;
        half_k = k / 2;

        /*@
            loop invariant 0 <= half_k <= k/2;
            loop invariant result == (108 - ((k) / 2) - ((k) % 2)) + half_k;
            loop invariant result >= 0;
            loop assigns result, half_k;
            loop variant half_k;
        */
        while (half_k > 0)
        {
            //@ assert half_k > 0;
            result -= 1;
            half_k -= 1;
            //@ assert result == (108 - ((k) / 2) - ((k) % 2)) + half_k;
        }
        //@ assert half_k == 0;
        //@ assert result == (108 - ((k) / 2) - ((k) % 2));
        return result;
    }
}
