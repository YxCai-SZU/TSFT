/*@
    predicate valid_inputs(integer A, integer P) =
        0 <= A && A <= 100 &&
        0 <= P && P <= 100;

    logic integer total_sum(integer A, integer P) = A * 3 + P;

    lemma ans_bounds:
        \forall integer A, P, sum, ans, count;
        valid_inputs(A, P) && sum == total_sum(A, P) &&
        0 <= ans && ans <= (sum - count) / 2 &&
        0 <= count && count <= sum ==>
        ans >= 0 && ans <= total_sum(A, P);
*/

/*@
    requires valid_inputs(A, P);
    ensures \result >= 0;
    ensures \result <= total_sum(A, P);
*/
int func(int A, int P)
{
    int sum;
    int ans;
    int count;

    sum = A * 3 + P;
    ans = 0;
    count = sum;

    /*@
        loop invariant 0 <= ans;
        loop invariant ans <= (sum - count) / 2;
        loop invariant 0 <= count && count <= sum;
        loop invariant sum == total_sum(A, P);
        loop invariant valid_inputs(A, P);
        loop assigns ans, count;
    */
    while (count >= 2)
    {
        ans = ans + 1;
        count = count - 2;
    }

    //@ assert ans >= 0 && ans <= total_sum(A, P);
    return ans;
}
