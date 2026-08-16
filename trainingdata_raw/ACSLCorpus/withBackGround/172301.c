/*@
    predicate valid_input(integer n, integer m, integer k) =
        1 <= n && n <= 1000 &&
        1 <= m && m <= 1000 &&
        0 <= k && k <= n * m;

    logic integer product(integer n, integer m) = n * m;
    logic integer boundary(integer n, integer m) = 2 * (n + m) - 4;
*/

/*@
    requires valid_input(n, m, k);
    ensures \result == (product(n, m) - k <= boundary(n, m));
*/
int func(int n, int m, int k) {
    int a;
    int b;
    int c;
    int result;

    //@ assert n * m <= 1000 * 1000;
    //@ assert n + m <= 1000 + 1000;
    //@ assert 2 * (n + m) <= 2 * 2000;
    //@ assert 2 * (n + m) - 4 <= 2 * 2000 - 4;

    a = n * m;
    b = k;
    a = a - b;
    c = n + m;
    c = c * 2;
    c = c - 4;
    result = (a <= c);
    return result;
}
