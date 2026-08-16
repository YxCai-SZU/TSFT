/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    logic integer total_sum(integer a, integer b, integer c, integer d, integer e) = a + b + c + d + e;

    lemma sum_ge_five: \forall integer a, b, c, d, e;
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) && valid_range(e) ==>
        total_sum(a, b, c, d, e) >= 5;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) && valid_range(e);
    ensures \result == total_sum(a, b, c, d, e) - 5;
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e)
{
    int sum = a + b + c + d + e;
    int result = sum;
    int count = 0;

    /*@
        loop invariant valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) && valid_range(e);
        loop invariant sum == total_sum(a, b, c, d, e);
        loop invariant result == sum - count;
        loop invariant 0 <= count <= 5;
        loop invariant sum >= 5;
        loop assigns result, count;
    */
    while (count < 5)
    {
        //@ assert result == sum - count;
        result -= 1;
        count += 1;
    }

    //@ assert result == sum - 5;
    return result;
}
