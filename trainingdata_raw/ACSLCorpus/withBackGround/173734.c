/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer compute_result(integer a, integer b) = (a * b + 1) / 2;
    
    lemma product_bound: \forall integer a, b; valid_range(a) && valid_range(b) ==> a * b <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int result;
    unsigned int product;
    
    //@ assert a * b <= 10000;
    
    result = 0;
    product = a * b;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant result == (a * b - product) / 2;
        loop invariant product <= a * b;
        loop invariant result >= 0;
        loop invariant result <= (a * b) / 2;
        loop invariant product + 2 * result == a * b;
        loop invariant a * b <= 10000;
        loop assigns product, result;
        loop variant product;
    */
    while (product >= 2) {
        product -= 2;
        result += 1;
    }
    
    if (product == 1) {
        result += 1;
    }
    
    //@ assert result == (a * b + 1) / 2;
    
    return result;
}
