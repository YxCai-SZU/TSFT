/*@
    predicate is_valid_params(integer n, integer r) =
        1 <= n && n <= 100 &&
        0 <= r && r <= 4111;

    logic integer compute_ans(integer n, integer r) =
        n < 10 ? r + 100 * (10 - n) : r;

    lemma ans_lower_bound:
        \forall integer n, r;
        is_valid_params(n, r) ==> compute_ans(n, r) >= 0;

    lemma ans_upper_bound:
        \forall integer n, r;
        is_valid_params(n, r) ==> compute_ans(n, r) <= 4111 + 100 * 9;
*/

/*@
    requires is_valid_params(n, r);
    ensures (n < 10 ==> \result == r + 100 * (10 - n));
    ensures (n >= 10 ==> \result == r);
*/
int func(int n, int r)
{
    int ans;
    //@ assert r >= 0;
    //@ assert r <= 4111;
    
    if (n < 10) {
        ans = r + 100 * (10 - n);
        //@ assert ans >= 0;
    } else {
        ans = r;
    }
    
    return ans;
}
