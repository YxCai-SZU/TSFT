/*@
    predicate valid_inputs(integer A, integer P) =
        0 <= A && A <= 100 &&
        0 <= P && P <= 100;

    logic integer compute_sum(integer A, integer P) = A * 3 + P;

    lemma ans_bounds:
        \forall integer A, P, ans;
        valid_inputs(A, P) && 0 <= ans && ans <= compute_sum(A, P) / 2 ==>
        ans >= 0 && ans <= compute_sum(A, P);
*/

/*@
    requires valid_inputs(A, P);
    ensures \result >= 0;
    ensures \result <= compute_sum(A, P);
*/
long func(long A, long P)
{
    long sum;
    long ans;
    long count;

    sum = A * 3 + P;
    ans = 0;
    count = sum;

    /*@
        loop invariant 0 <= A && A <= 100;
        loop invariant 0 <= P && P <= 100;
        loop invariant sum == compute_sum(A, P);
        loop invariant 0 <= ans && ans <= sum / 2;
        loop invariant count == sum - 2 * ans;
        loop invariant ans >= 0 && ans <= compute_sum(A, P);
        loop assigns ans, count;
        loop variant count;
    */
    while (count >= 2)
    {
        //@ assert count >= 2;
        ans += 1;
        count -= 2;
    }

    return ans;
}
