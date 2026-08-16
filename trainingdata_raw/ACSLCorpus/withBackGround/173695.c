/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 1000000000 && 1 <= k <= n;
    
    logic integer result_value(integer n, integer k) = n - k + 1;
*/

/*@
    requires valid_params(n, k);
    ensures \result == result_value(n, k);
    assigns \nothing;
*/
long func(long n, long k)
{
    long ans = 0;
    
    //@ assert 1 <= n - k + 1 <= n;
    ans = n - k + 1;
    
    return ans;
}
