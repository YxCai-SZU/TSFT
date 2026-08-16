/*@
    logic integer double_val(integer x) = x * 2;
    
    predicate even_i_even_f(integer i) = 
        0 <= i && i <= 100 && i % 2 == 0 ==> double_val(i) == i * 2;
    
    lemma lemma_even_i_even_f: \forall integer i; even_i_even_f(i);
*/

/*@
    requires 0 <= i && i <= 100;
    requires i % 2 == 0;
    ensures \true;
*/
void lemma_even_i_even_f_proof(int i) {
    //@ assert double_val(i) == i * 2;
}

int main() {
    return 0;
}
