/*@
    predicate is_positive(integer x) = x > 0;
    predicate product_le_1000(integer x, integer y) = x * y <= 1000;
    logic integer product(integer x, integer y) = x * y;
    lemma product_bound: \forall integer a, b, c, d;
        is_positive(a) && is_positive(b) && is_positive(c) && is_positive(d) &&
        product_le_1000(a, b) && product_le_1000(c, d) ==>
        product(a, b) <= 1000 && product(c, d) <= 1000;
*/

/*@
    requires is_positive(a) && is_positive(b) && is_positive(c) && is_positive(d);
    requires product_le_1000(a, b) && product_le_1000(c, d);
    ensures \result == (product(a, b) >= product(c, d));
*/
int non_linear_arith_example(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    // Variable declarations at top of scope
    int result;

    //@ assert product(a, b) <= 1000;
    //@ assert product(c, d) <= 1000;
    
    result = (a * b >= c * d);
    return result;
}
