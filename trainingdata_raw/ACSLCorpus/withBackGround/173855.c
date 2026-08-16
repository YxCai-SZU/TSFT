/*@
    predicate valid_params(integer n, integer k, integer x, integer y) =
        1 <= n <= 10000 &&
        1 <= k <= 10000 &&
        1 <= y < x <= 10000;

    logic integer func_result(integer n, integer k, integer x, integer y) =
        n <= k ? n * x : k * x + (n - k) * y;

    lemma overflow_bound_n_x:
        \forall integer n, integer x;
        1 <= n <= 10000 && 1 <= x <= 10000 ==> n * x <= 100000000;

    lemma overflow_bound_k_x_plus_rest:
        \forall integer k, integer x, integer n, integer y;
        1 <= k <= 10000 && 1 <= x <= 10000 &&
        1 <= n - k <= 9999 && 1 <= y <= 9999 ==>
        k * x + (n - k) * y <= 199980001;
*/

/*@
    requires valid_params(n, k, x, y);
    ensures \result == func_result(n, k, x, y);
    assigns \nothing;
*/
int func(int n, int k, int x, int y)
{
    int res;

    //@ assert 1 <= n <= 10000;
    //@ assert 1 <= k <= 10000;
    //@ assert 1 <= y < x <= 10000;

    if (n <= k)
    {
        //@ assert 1 <= n && n <= 10000;
        //@ assert 1 <= x && x <= 10000;
        //@ assert n * x <= 100000000;
        res = n * x;
    }
    else
    {
        //@ assert 1 <= k && k <= 10000;
        //@ assert 1 <= x && x <= 10000;
        //@ assert 1 <= n - k && n - k <= 9999;
        //@ assert 1 <= y && y <= 9999;
        //@ assert k * x + (n - k) * y <= 199980001;
        res = k * x + (n - k) * y;
    }

    //@ assert res == func_result(n, k, x, y);
    return res;
}
