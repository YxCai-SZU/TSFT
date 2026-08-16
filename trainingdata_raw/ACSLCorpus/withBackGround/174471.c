/*@
    predicate is_nonnegative(integer x) = x >= 0;

    logic integer compute_result(integer n, integer m) =
        n - m * 2;

    lemma result_property:
        \forall integer n, m;
            1 <= n <= 100 && 1 <= m <= 100 ==>
            (compute_result(n, m) >= 0 ==> compute_result(n, m) == n - m * 2) &&
            (compute_result(n, m) < 0 ==> 0 == 0);
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result >= 0;
    ensures \result == n - m * 2 || \result == 0;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;

    result = n - m * 2;
    //@ assert result == n - m * 2;

    if (result > 0)
    {
        //@ assert result == n - m * 2;
        return result;
    }
    else
    {
        //@ assert result <= 0;
        return 0;
    }
}
