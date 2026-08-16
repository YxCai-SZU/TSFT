/*@
    predicate valid_range(integer a, integer p) =
        0 <= a <= 100 && 0 <= p <= 100;

    logic integer calculate_sum(integer a, integer p) =
        a * 3 + p;

    lemma division_property:
        \forall integer a, p, sum, result;
        valid_range(a, p) && sum == calculate_sum(a, p) && result == sum / 2 ==>
        result >= 0 && result <= sum;
*/

/*@
    requires valid_range(a, p);
    ensures \result >= 0;
    ensures \result <= calculate_sum(a, p);
    ensures \result == calculate_sum(a, p) / 2;
*/
int func(int a, int p)
{
    int sum;
    int result;
    int count;
    int temp_sum;

    sum = a * 3 + p;
    result = 0;
    count = 0;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant sum == calculate_sum(a, p);
        loop invariant temp_sum + 2 * count == sum;
        loop assigns temp_sum, count;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }

    result = count;
    //@ assert result == sum / 2;
    return result;
}
