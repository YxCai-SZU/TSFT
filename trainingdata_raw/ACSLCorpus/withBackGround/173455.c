/*@
    predicate sum_bounds(integer n) =
        1 <= n <= 100 &&
        0 <= n * (n + 1) <= 100 * 101;

    logic integer target_sum(integer n) = n * (n + 1) / 2;

    lemma product_bounds: \forall integer n; sum_bounds(n) ==> 0 <= n * (n + 1) <= 100 * 101;
*/

/*@
    requires 1 <= n <= 100;
    ensures \result == n * (n + 1) / 2;
    assigns \nothing;
*/
long func(long n)
{
    // Variable declarations at top
    long sum;
    long result = 0;
    long count = 0;
    long temp_sum;

    //@ assert sum_bounds(n);
    //@ assert 0 <= n * (n + 1) <= 100 * 101;

    sum = n * (n + 1);
    temp_sum = sum;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop invariant sum == n * (n + 1);
        loop invariant sum <= 100 * 101;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
        //@ assert temp_sum == sum - 2 * count;
    }

    result = count;
    //@ assert result == n * (n + 1) / 2;
    return result;
}
