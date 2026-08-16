/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * 3 + (p));
    assigns \nothing;
*/
long func(long a, long p)
{
    long sum;
    long result;
    long temp_sum;
    long count;

    sum = a * 3 + p;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }

    result = count;
    //@ assert result >= 0;
    //@ assert result <= ((a) * 3 + (p));
    return result;
}
