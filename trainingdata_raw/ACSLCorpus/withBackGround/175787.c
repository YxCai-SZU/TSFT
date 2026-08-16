/*@
    predicate bounds(integer a, integer b) =
        0 <= a && a <= 100 &&
        0 <= b && b <= 100;
    
    logic integer product(integer a, integer b) = a * b;
    logic integer half_sum(integer a, integer b) = (a + b) / 2;
    
    lemma product_bound: \forall integer a, b; bounds(a, b) ==> product(a, b) <= 10000;
*/

/*@
    requires bounds(a, b);
    ensures \result <= product(a, b);
    ensures \result == half_sum(a, b) || \result == product(a, b);
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int product;
    unsigned int half_sum;
    unsigned int min_value;
    
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert a * b <= 10000;
    
    product = a * b;
    half_sum = (a + b) / 2;
    
    if (product < half_sum) {
        min_value = product;
    } else {
        min_value = half_sum;
    }
    
    return min_value;
}
