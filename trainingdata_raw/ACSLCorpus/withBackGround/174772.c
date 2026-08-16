/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= n && m <= 5;

    logic integer expected_result(integer n, integer m) =
        100 * (n - m) + 1900 * m;

    lemma ans_preserved:
        \forall integer n, m, ans;
        valid_params(n, m) && ans == expected_result(n, m) ==>
        ans == expected_result(n, m);
*/

/*@
    requires valid_params(n, m);
    ensures \result == expected_result(n, m);
    assigns \nothing;
*/
int func(int n, int m) {
    int ans;
    int i;

    //@ assert valid_params(n, m);
    ans = 100 * (n - m) + 1900 * m;

    i = 0;
    /*@
        loop invariant 0 <= i <= m;
        loop invariant ans == expected_result(n, m);
        loop assigns i;
        loop variant m - i;
    */
    while (i < m) {
        i = i + 1;
    }

    i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == expected_result(n, m);
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        i = i + 1;
    }

    i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant ans == expected_result(n, m);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        i = i + 1;
    }

    //@ assert ans == expected_result(n, m);
    return ans;
}

int main() {
    return 0;
}
