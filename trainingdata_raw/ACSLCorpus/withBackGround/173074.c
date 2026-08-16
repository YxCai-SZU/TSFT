/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 1000000000 && 1 <= k <= n;
    
    logic integer compute_result(integer n, integer k) = n - k + 1;
    
    lemma result_bounds: \forall integer n, k;
        valid_params(n, k) ==> 1 <= compute_result(n, k) <= n - k + 1;
*/

/*@
    requires valid_params(n, k);
    ensures 1 <= \result <= n - k + 1;
    assigns \nothing;
*/
long func(long n, long k)
{
    long ans;
    //@ assert valid_params(n, k);
    
    ans = n - k + 1;
    
    //@ assert 1 <= ans <= n - k + 1;
    
    return ans;
}
