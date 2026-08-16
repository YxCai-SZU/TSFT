/*@
    predicate is_in_range(integer x) = 1 <= x <= 100;

    logic integer sum_val(integer a, integer b) = a + b;

    lemma average_bound: \forall integer a, b, avg, rem;
        is_in_range(a) && is_in_range(b) && 0 <= avg && 0 <= rem <= sum_val(a, b) &&
        sum_val(a, b) - rem == avg * 2 ==>
        avg <= sum_val(a, b) / 2;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a + b + 1) / 2;
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int average;
    int remainder;

    sum = a + b;
    average = 0;
    remainder = sum;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 0 <= remainder <= sum;
        loop invariant sum == a + b;
        loop invariant average <= (a + b) / 2;
        loop invariant sum - remainder == average * 2;
        loop invariant 0 <= average;
        loop assigns average, remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        //@ assert remainder >= 2;
        average += 1;
        remainder -= 2;
    }

    //@ assert 0 <= remainder <= 1;
    if (remainder > 0 && sum > 0)
    {
        //@ assert remainder == 1;
        average += 1;
    }

    //@ assert average == (a + b + 1) / 2;
    return average;
}
