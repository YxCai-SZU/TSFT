/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= n;

    logic integer compute_result(integer n, integer k) = n - k + 1;

    lemma result_lower_bound: \forall integer n, k; valid_params(n, k) ==> compute_result(n, k) >= 1;
    lemma result_upper_bound: \forall integer n, k; valid_params(n, k) ==> compute_result(n, k) <= n;
*/

/*@
    requires valid_params(n, k);
    ensures \result >= 1;
    ensures \result <= n;
    ensures \result == n - k + 1;
    assigns \nothing;
*/
long func(long n, long k)
{
    long result;

    //@ assert valid_params(n, k);
    //@ assert compute_result(n, k) >= 1;
    //@ assert compute_result(n, k) <= n;

    result = n - k + 1;
    return result;
}
