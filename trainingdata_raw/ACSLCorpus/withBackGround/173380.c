/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    
    logic integer compute_result(integer a, integer b) =
        a - b * 2;
    
    lemma result_nonnegative:
        \forall integer a, b;
        valid_range(a, b) && compute_result(a, b) >= 0 ==>
        compute_result(a, b) >= 0;
    
    lemma result_zero_or_original:
        \forall integer a, b, r;
        valid_range(a, b) && r >= 0 &&
        (r == compute_result(a, b) || r == 0) ==>
        (r == compute_result(a, b) || r == 0);
*/

/*@
    requires valid_range(A, B);
    ensures \result >= 0;
    ensures \result == compute_result(A, B) || \result == 0;
    assigns \nothing;
*/
long func(long A, long B)
{
    long result;
    
    //@ assert valid_range(A, B);
    result = A - B * 2;
    
    if (result < 0)
    {
        //@ assert compute_result(A, B) < 0;
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == compute_result(A, B) || result == 0;
    return result;
}
