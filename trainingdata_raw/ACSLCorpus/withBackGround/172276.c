/*@
    predicate is_valid_params(integer n, integer w) =
        n >= 1 && n <= 100 &&
        w >= 1 && w <= 100;

    lemma ans_mult_n_equals_n_mult_w:
        \forall integer ans, n, w;
            ans == w && is_valid_params(n, w) ==>
            ans * n == n * w;

    lemma ans_mult_n_in_range:
        \forall integer ans, n, w;
            0 <= ans && ans <= 100 && is_valid_params(n, w) ==>
            0 <= ans * n <= 100 * 100;
*/

/*@
    requires is_valid_params(n, w);
    ensures \result == n * w;
    ensures 0 <= \result <= 100 * 100;
*/
int func(int n, int w)
{
    int ans = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= w;
        loop invariant ans == i;
        loop invariant is_valid_params(n, w);
        loop assigns ans, i;
    */
    while (i < w)
    {
        ans += 1;
        i += 1;
    }

    //@ assert ans == w;
    //@ assert ans * n == n * w;
    //@ assert 0 <= ans * n <= 100 * 100;
    
    ans = ans * n;
    return ans;
}
