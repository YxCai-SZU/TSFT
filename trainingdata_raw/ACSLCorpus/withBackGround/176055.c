/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= 41;

    logic integer compute_res(integer n, integer k) =
        n > 2 * k ? n - 2 * k : 0;

    lemma res_properties:
        \forall integer n, k;
        valid_params(n, k) ==>
            compute_res(n, k) >= 0 &&
            compute_res(n, k) <= n &&
            (compute_res(n, k) == n - 2 * k || compute_res(n, k) == 0);
*/

/*@
    requires valid_params(n, k);
    ensures \result >= 0 && \result <= n;
    ensures \result == n - 2 * k || \result == 0;
    assigns \nothing;
*/
int func(int n, int k)
{
    int res;
    //@ assert valid_params(n, k);
    
    if (n > 2 * k)
    {
        res = n - 2 * k;
        //@ assert res == n - 2 * k;
    }
    else
    {
        res = 0;
        //@ assert res == 0;
    }
    
    //@ assert res >= 0 && res <= n;
    //@ assert res == n - 2 * k || res == 0;
    
    return res;
}
