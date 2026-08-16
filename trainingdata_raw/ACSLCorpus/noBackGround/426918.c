/*@
    requires 2 <= k <= 1000000000;
    ensures \result >= 0;
    ensures \result <= k;
    ensures (k - 2 * \result) >= 0;
    assigns \nothing;
*/
long func(long k)
{
    long count = 0;
    long temp_k = k;

    /*@
        loop invariant 0 <= temp_k <= k;
        loop invariant 0 <= count <= k / 2;
        loop invariant temp_k == k - 2 * count;
        loop assigns temp_k, count;
        loop variant temp_k;
    */
    while (temp_k >= 2)
    {
        //@ assert temp_k >= 2;
        long old_temp_k = temp_k;
        temp_k -= 2;
        count += 1;
        //@ assert temp_k == old_temp_k - 2;
    }

    //@ assert (k - 2 * count) >= 0;
    return count;
}
