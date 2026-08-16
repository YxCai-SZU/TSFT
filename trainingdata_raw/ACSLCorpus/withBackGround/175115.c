/*@
    predicate is_valid_range(integer n) = 1 <= n <= 100;

    predicate loop_invariant(integer n, integer i, integer res) =
        1 <= n <= 100 &&
        1 <= i <= n + 1 &&
        res >= 0 &&
        res <= i - 1;

    lemma decreases_positive: \forall integer n, i; 1 <= i <= n + 1 ==> n - i + 1 >= 0;
*/

/*@
    requires is_valid_range(n);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n)
{
    int res = 0;
    int i = 1;

    /*@
        loop invariant loop_invariant(n, i, res);
        loop assigns res, i;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        //@ assert res >= 0;
        res += 1;
        i += 1;
        //@ assert res <= i - 1;
    }

    //@ assert res >= 0;
    return res;
}
