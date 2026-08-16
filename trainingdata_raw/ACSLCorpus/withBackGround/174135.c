/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        0 <= m && m <= n;

    lemma n_m_relation: \forall integer n, m; valid_params(n, m) ==> (n == m) || (n != m);
*/

/*@
    requires valid_params(n, m);
    ensures \result == (n == m);
    assigns \nothing;
*/
int func(int n, int m) {
    int i;

    // First sleep loop
    i = 0;
    /*@
        loop invariant 0 <= i && i <= n * 1000000;
        loop invariant valid_params(n, m);
        loop assigns i;
    */
    while (i < n * 1000000) {
        i++;
    }

    // Second sleep loop
    i = 0;
    /*@
        loop invariant 0 <= i && i <= m * 1000000;
        loop invariant valid_params(n, m);
        loop assigns i;
    */
    while (i < m * 1000000) {
        i++;
    }

    // Third sleep loop
    i = 0;
    /*@
        loop invariant 0 <= i && i <= (n - m) * 1000000;
        loop invariant valid_params(n, m);
        loop assigns i;
    */
    while (i < (n - m) * 1000000) {
        i++;
    }

    // Fourth sleep loop
    i = 0;
    /*@
        loop invariant 0 <= i && i <= n * 100000;
        loop invariant valid_params(n, m);
        loop assigns i;
    */
    while (i < n * 100000) {
        i++;
    }

    // Fifth sleep loop
    i = 0;
    /*@
        loop invariant 0 <= i && i <= m * 100000;
        loop invariant valid_params(n, m);
        loop assigns i;
    */
    while (i < m * 100000) {
        i++;
    }

    // Sixth sleep loop
    i = 0;
    /*@
        loop invariant 0 <= i && i <= (n - m) * 100000;
        loop invariant valid_params(n, m);
        loop assigns i;
    */
    while (i < (n - m) * 100000) {
        i++;
    }

    //@ assert n == m || n != m;
    return n == m;
}

int main() {
    return 0;
}
