/*@
    predicate valid_input(integer A, integer P) =
        0 <= A && A <= 100 &&
        0 <= P && P <= 100;

    logic integer compute_ans(integer A, integer P) = A * 3 + P;

    lemma ans_nonnegative:
        \forall integer A, P;
        valid_input(A, P) ==> compute_ans(A, P) >= 0;
*/

/*@
    requires valid_input(A, P);
    ensures \result >= 0;
    ensures \result == (A * 3 + P) / 2;
*/
int func(int A, int P)
{
    int ans;
    int result;
    int temp;
    int count;

    ans = A * 3 + P;

    result = 0;
    temp = ans;
    count = 0;

    /*@
        loop invariant 0 <= temp <= ans;
        loop invariant 0 <= count <= ans / 2;
        loop invariant temp == ans - 2 * count;
        loop assigns temp, count;
    */
    while (temp >= 2)
    {
        temp -= 2;
        count += 1;
    }
    result = count;

    //@ assert ans == A * 3 + P;
    //@ assert ans / 2 == (A * 3 + P) / 2;

    return result;
}
