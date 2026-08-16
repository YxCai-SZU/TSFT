/*@
    predicate bounds(integer a, integer b) =
        0 < a && a < 100 && 0 < b && b < 100;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bounds:
        \forall integer a, b;
        bounds(a, b) ==> 0 < product(a, b) && product(a, b) < 10000;
*/

/*@
    requires bounds(a, b);
    ensures \result == (a * b > 0);
    assigns \nothing;
*/
int non_linear_arith_example(unsigned int a, unsigned int b) {
    // Variable declarations at top
    int result;
    
    //@ assert bounds(a, b);
    
    //@ assert 0 < a * b && a * b < 10000;
    
    result = (a * b > 0);
    return result;
}
