/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= 100;

    predicate loop_invariant(integer a, integer n, integer k, integer x) =
        0 <= a <= n &&
        valid_params(n, k) &&
        x >= 0 &&
        x <= k &&
        (a > 0 ==> x <= k) &&
        (a > 0 ==> x >= 0);
*/

/*@
    requires valid_params(n, k);
    ensures \result >= 0 && \result <= 1;
    assigns \nothing;
*/
int func(int n, int k)
{
    int x;
    int a;
    int res;

    x = 0;
    a = 0;

    /*@
        loop invariant loop_invariant(a, n, k, x);
        loop assigns a, x;
        loop variant n - a;
    */
    while (a < n)
    {
        //@ assert x >= 0 && x <= k;
        if (x == k)
        {
            //@ assert 1 >= 0 && 1 <= 1;
            return 1;
        }
        a += 1;
    }

    //@ assert 0 >= 0 && 0 <= 1;
    return 0;
}
