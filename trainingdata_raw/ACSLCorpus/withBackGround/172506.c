/*@
    predicate valid_inputs(integer A, integer P) =
        0 <= A && A <= 100 &&
        0 <= P && P <= 100;

    logic integer compute_sum(integer A, integer P) = A * 3 + P;

    lemma sum_nonnegative:
        \forall integer A, P; valid_inputs(A, P) ==> compute_sum(A, P) >= 0;
*/

/*@
    requires valid_inputs(A, P);
    ensures \result >= 0;
    ensures \result == compute_sum(A, P) / 2;
*/
int func(int A, int P)
{
    int sum;
    int result;
    int count;

    //@ assert valid_inputs(A, P);
    sum = A * 3 + P;
    result = 0;
    count = sum;

    /*@
        loop invariant 0 <= count <= compute_sum(A, P);
        loop invariant result == (compute_sum(A, P) - count) / 2;
        loop invariant count % 2 == sum % 2;
        loop assigns count, result;
    */
    while (count >= 2)
    {
        //@ assert count >= 2;
        count -= 2;
        result += 1;
    }

    //@ assert result >= 0;
    //@ assert result == compute_sum(A, P) / 2;
    return result;
}
