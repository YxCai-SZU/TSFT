/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10;

    logic integer n_squared(integer n) = n * n;
    logic integer n_cubed(integer n) = n * n * n;
    logic integer expected_result(integer n) = n + n_squared(n) + n_cubed(n);

    lemma n_squared_bounds: \forall integer n; is_valid_n(n) ==> 1 <= n_squared(n) && n_squared(n) <= 100;
    lemma n_cubed_bounds: \forall integer n; is_valid_n(n) ==> 1 <= n_cubed(n) && n_cubed(n) <= 1000;
*/

/*@
    requires 1 <= n && n <= 10;
    ensures \result == n + (n * n) + (n * n * n);
    assigns \nothing;
*/
long func(long n) {
    long n_2;
    long n_3;
    long result;

    //@ assert 1 <= n && n <= 10;
    //@ assert 1 <= n * n && n * n <= 100;
    n_2 = n * n;
    //@ assert 1 <= n * n * n && n * n * n <= 1000;
    n_3 = n * n * n;
    result = n + n_2 + n_3;
    //@ assert result == n + (n * n) + (n * n * n);
    return result;
}
