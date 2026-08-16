/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;

    logic integer compute_result(integer n, integer m) =
        (n * 2 * 3) - m;

    lemma result_nonnegative:
        \forall integer n, m;
        valid_range(n, m) ==> compute_result(n, m) >= -20;
*/

/*@
    requires valid_range(n, m);
    ensures \result == compute_result(n, m) || \result == 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;

    //@ assert 1 <= n <= 20;
    //@ assert 1 <= m <= 20;
    
    result = (n * 2 * 3) - m;
    
    //@ assert result >= -20;
    
    if (result > 0)
    {
        //@ assert result == compute_result(n, m);
        return result;
    }
    else
    {
        //@ assert result <= 0;
        return 0;
    }
}
