/*@
    predicate valid_range(integer x) = 1 <= x <= 3;
    
    logic integer compute_c(integer a, integer b) = 6 - a - b;
    
    lemma c_in_range: \forall integer a, b; 
        valid_range(a) && valid_range(b) && a != b ==> 
        valid_range(compute_c(a, b));
    
    lemma c_distinct: \forall integer a, b; 
        valid_range(a) && valid_range(b) && a != b ==> 
        compute_c(a, b) != a && compute_c(a, b) != b;
*/

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    requires a != b;
    ensures \result >= 1 && \result <= 3;
    ensures \result != a && \result != b;
*/
int func(int a, int b)
{
    int c;
    
    //@ ghost int a_val = a;
    //@ ghost int b_val = b;
    
    c = 6 - a - b;
    
    //@ assert valid_range(compute_c(a_val, b_val));
    
    return c;
}
