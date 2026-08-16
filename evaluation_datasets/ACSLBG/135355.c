/*@
    predicate is_positive(integer a) = a > 0;
    
    logic integer product(integer a, integer b) = 
        a <= 0 || b <= 0 ? 0 : a * b;
    
    lemma product_is_positive:
        \forall integer a, b; 
        is_positive(a) && is_positive(b) ==> 
        product(a, b) > 0;
*/

int main() {
    //@ assert product(5, 3) == 15;
    return 0;
}
