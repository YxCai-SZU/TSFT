/*@
    predicate is_valid_params(integer n, integer m) =
        n >= 1 && n <= 100 && m >= 1 && m <= 100;
    
    logic integer compute_ans(integer n, integer m) = n - 2 * m;
    
    lemma ans_property:
        \forall integer n, m;
        is_valid_params(n, m) ==>
        (compute_ans(n, m) > 0 ==> compute_ans(n, m) == n - 2 * m) &&
        (compute_ans(n, m) <= 0 ==> 0 == n - 2 * m || 0 == 0);
*/

/*@
    requires is_valid_params(n, m);
    ensures \result >= 0;
    ensures \result == n - 2 * m || \result == 0;
*/
int func(int n, int m)
{
    int ans;
    
    //@ assert is_valid_params(n, m);
    
    ans = n - 2 * m;
    
    //@ assert ans == compute_ans(n, m);
    
    if (ans > 0)
    {
        //@ assert ans == n - 2 * m;
        return ans;
    }
    else
    {
        //@ assert 0 == n - 2 * m || 0 == 0;
        return 0;
    }
}
