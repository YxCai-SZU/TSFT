/*@
    predicate bounds(integer x, integer y) = 0 <= x && x <= 20 && 0 <= y && y <= 30;
    logic integer product(integer x, integer y) = x * y;
    lemma product_bound: \forall integer x, y; bounds(x, y) ==> product(x, y) <= 600;
*/

/*@
    requires bounds(x, y);
    ensures \result == product(x, y);
    ensures \result <= 600;
    assigns \nothing;
*/
unsigned int nonlinear_arith_example(unsigned int x, unsigned int y) {
    // Variable declarations at scope top
    unsigned int result;

    //@ assert bounds(x, y);
    
    result = x * y;
    
    //@ assert result == product(x, y);
    //@ assert result <= 600;
    
    return result;
}
