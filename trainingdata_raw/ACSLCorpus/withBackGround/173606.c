/*@
    predicate valid_params(integer n, integer a) =
        1 <= n && n <= 100 &&
        0 <= a && a <= n * n;

    logic integer n_squared(integer n) = n * n;

    logic integer func_result(integer n, integer a) = n * n - a;

    lemma n_squared_bounds:
        \forall integer n; 1 <= n && n <= 100 ==> 0 <= n_squared(n) && n_squared(n) <= 10000;

    lemma result_bounds:
        \forall integer n, integer a;
            valid_params(n, a) ==> 0 <= func_result(n, a) && func_result(n, a) <= 10000;
*/

/*@
    requires valid_params(n, a);
    ensures \result == func_result(n, a);
    ensures 0 <= \result && \result <= 10000;
*/
long func(long n, long a)
{
    // Variable declarations at top of scope
    long n_squared;
    long result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;

    // Calculate n^2
    n_squared = n * n;
    //@ assert n_squared == n_squared(n);

    // Verify n_squared bounds
    //@ assert 0 <= n_squared && n_squared <= 10000;

    // Calculate result
    result = n_squared - a;
    //@ assert result == func_result(n, a);

    // Verify result bounds
    //@ assert 0 <= result && result <= 10000;

    return result;
}
