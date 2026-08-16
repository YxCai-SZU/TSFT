/*@
    predicate non_negative(integer x) = x >= 0;
    predicate within_k(integer x, integer k) = 0 <= x && x <= k;
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c &&
        1 <= k && k <= a + b + c && k <= 2000000000;

    lemma ans_non_negative:
        \forall integer a, b, c, k, ans, rst;
        valid_params(a, b, c, k) &&
        ans == (a < k ? a : k) &&
        rst == k - (a < k ? a : k) &&
        rst == rst - (b < rst ? b : rst) &&
        ans == ans - (rst < 0 ? rst : 0) ==>
        ans >= 0;

    lemma ans_within_k:
        \forall integer a, b, c, k, ans, rst;
        valid_params(a, b, c, k) &&
        ans == (a < k ? a : k) &&
        rst == k - (a < k ? a : k) &&
        rst == rst - (b < rst ? b : rst) &&
        ans == ans - (rst < 0 ? rst : 0) ==>
        ans <= k;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures within_k(\result, k);
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans = 0;
    int rst = k;

    //@ assert valid_params(a, b, c, k);
    //@ assert non_negative(ans);
    //@ assert within_k(rst, k);

    ans += (a < rst) ? a : rst;
    //@ assert within_k(ans, k);

    rst -= (a < rst) ? a : rst;
    //@ assert non_negative(rst);

    rst -= (b < rst) ? b : rst;
    //@ assert non_negative(rst);

    ans -= (rst < 0) ? rst : 0;
    //@ assert within_k(ans, k);

    //@ assert ans_non_negative: ans >= 0;
    //@ assert ans_within_k: ans <= k;

    return ans;
}
