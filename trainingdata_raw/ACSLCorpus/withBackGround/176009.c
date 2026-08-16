/*@
    predicate valid_range(integer x) = 1 <= x && x <= 10;

    logic integer compute_result(integer x) = 3 * x + 7;

    lemma result_ge_10: \forall integer x; valid_range(x) ==> compute_result(x) >= 10;
*/

/*@
    requires valid_range(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
int func(int x)
{
    int result;

    //@ assert valid_range(x);
    
    //@ assert compute_result(x) >= 10;
    
    result = 3 * x + 7;
    
    //@ assert result == compute_result(x);
    
    return result;
}
