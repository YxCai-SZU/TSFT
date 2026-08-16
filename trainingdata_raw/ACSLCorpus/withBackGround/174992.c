/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && n <= 100 &&
        1 <= k && k <= n;

    logic integer expected_result(integer n, integer k) =
        n - k + 1;
*/

/*@
    requires valid_params(n, k);
    ensures \result == expected_result(n, k);
    assigns \nothing;
*/
int func(int n, int k)
{
    int ans;
    //@ assert valid_params(n, k);
    ans = n - k + 1;
    //@ assert ans == expected_result(n, k);
    return ans;
}

/*@
    requires valid_params(n, k);
    ensures \result == expected_result(n, k);
    assigns \nothing;
*/
int func1(int n, int k)
{
    int ans;
    //@ assert valid_params(n, k);
    ans = n - k + 1;
    //@ assert ans == expected_result(n, k);
    return ans;
}

/*@
    requires valid_params(n, k);
    ensures \result == expected_result(n, k);
    assigns \nothing;
*/
int func2(int n, int k)
{
    int ans;
    //@ assert valid_params(n, k);
    ans = n - k + 1;
    //@ assert ans == expected_result(n, k);
    return ans;
}
