/*@
    predicate valid_range(integer x) = 1 <= x <= 3;
    predicate distinct(integer a, integer b) = a != b;
    logic integer compute_result(integer a, integer b) = 6 - a - b;
    lemma result_properties: \forall integer a, b; 
        valid_range(a) && valid_range(b) && distinct(a, b) ==> 
        valid_range(compute_result(a, b)) && 
        compute_result(a, b) != a && 
        compute_result(a, b) != b;
*/

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    requires a != b;
    ensures \result == 6 - a - b;
    ensures 1 <= \result <= 3;
    ensures \result != a;
    ensures \result != b;
*/
int func(int a, int b)
{
    int result;
    //@ ghost int original_a = a;
    //@ ghost int original_b = b;
    
    result = 6 - a - b;
    
    //@ assert 6 - original_a - original_b >= 1;
    //@ assert 6 - original_a - original_b <= 3;
    //@ assert 6 - original_a - original_b != original_a;
    //@ assert 6 - original_a - original_b != original_b;
    //@ assert result == 6 - original_a - original_b;
    
    return result;
}
