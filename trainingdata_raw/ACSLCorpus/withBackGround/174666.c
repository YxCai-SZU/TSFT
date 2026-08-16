/*@
    predicate valid_range(integer n) = 1 <= n && n <= 100;

    logic integer compute_result(integer n) = n * 2 * 3;

    lemma result_correctness:
        \forall integer n; valid_range(n) ==> compute_result(n) == n * 2 * 3;
*/

/*@
    requires valid_range(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
int func(int n)
{
    int pi_approx;
    int result;

    pi_approx = 3;
    result = n * 2 * pi_approx;

    //@ assert result == n * 2 * 3;

    return result;
}
