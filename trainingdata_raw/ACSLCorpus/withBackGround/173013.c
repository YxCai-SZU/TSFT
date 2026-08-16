/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= n && m <= 5;

    logic integer initial_value(integer n) = 110 * n;

    logic integer lower_bound(integer n, integer i) = 
        110 * n - (i * 100);
*/

/*@
    requires valid_params(n, m);
    ensures \result >= 110 * n - (m * 100);
    ensures \result <= 110 * n;
    assigns \nothing;
*/
int func(int n, int m) {
    int ans;
    int i;

    //@ assert valid_params(n, m);
    ans = 110 * n;
    i = 0;

    /*@
        loop invariant 0 <= i <= m;
        loop invariant ans >= 110 * n - (i * 100);
        loop invariant ans <= 110 * n;
        loop assigns ans, i;
        loop variant m - i;
    */
    while (i < m) {
        //@ assert ans >= 110 * n - (i * 100);
        ans -= 100;
        i += 1;
        //@ assert ans >= 110 * n - (i * 100);
    }

    //@ assert ans >= 110 * n - (m * 100);
    return ans;
}
