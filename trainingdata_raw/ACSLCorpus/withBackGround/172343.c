/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer t, integer s) = t * s;
    
    lemma product_bound: 
        \forall integer t, s; 
        valid_range(t) && valid_range(s) ==> product(t, s) <= 100000000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (product(t, s) >= d);
    assigns \nothing;
*/
int func(int d, int t, int s) {
    // Variable declarations at scope top
    int product_val;
    int result;
    
    // Precondition assertions
    //@ assert valid_range(d);
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    
    // Arithmetic safety
    //@ assert product(t, s) <= 100000000;
    
    // Main logic
    product_val = t * s;
    
    // Postcondition verification
    //@ assert product_val == product(t, s);
    
    result = (product_val >= d) ? 1 : 0;
    
    // Final postcondition
    //@ assert result == (product(t, s) >= d);
    
    return result;
}
