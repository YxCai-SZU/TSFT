/*@
    predicate is_positive(integer x) = x > 0;
    predicate is_within_range(integer x) = x <= 1000;
    
    logic integer double_val(integer x) = x * 2;
    
    lemma double_positive:
        \forall integer x; is_positive(x) ==> double_val(x) > 0;
    
    lemma double_within_range:
        \forall integer x; is_within_range(x) ==> double_val(x) <= 2000;
*/

/*@
    requires is_positive(x) && is_within_range(x);
    ensures double_val(x) > 0 && double_val(x) <= 2000;
*/
void lemma_double_nonlinear_arith(int x) {
    //@ assert double_val(x) == x * 2;
    //@ assert x * 2 > 0;
    //@ assert x * 2 <= 2000;
}

void test() {
    int x = 10;
    //@ assert is_positive(x) && is_within_range(x);
    lemma_double_nonlinear_arith(x);
}
