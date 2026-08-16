/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer compute_result(integer r, integer pi) = r * 2 * pi;
    
    lemma result_correctness:
        \forall integer r, pi;
        valid_range(r) && pi == 3 ==> compute_result(r, pi) == r * 2 * 3;
*/

/*@
    requires valid_range(r);
    ensures \result == r * 2 * 3;
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int result;
    int temp;
    
    pi = 3;
    result = 0;
    temp = r * 2 * pi;
    
    //@ assert temp == r * 2 * pi;
    
    result = temp;
    
    //@ assert result == r * 2 * pi;
    
    return result;
}
