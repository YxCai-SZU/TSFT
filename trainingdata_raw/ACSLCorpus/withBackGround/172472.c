/*@
predicate is_even(integer i) = i % 2 == 0;

lemma lemma_even_f: \forall integer i; is_even(i) ==> \true;

lemma test_even_f: \forall integer i; is_even(i) ==> \true;
*/

int main() {
    // Variable declarations
    int i;
    
    //@ assert \true;
    
    return 0;
}
