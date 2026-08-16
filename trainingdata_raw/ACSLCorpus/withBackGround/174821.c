/*@
    predicate axiom_addition_inequality(integer a, integer b) = a < b ==> a < b + 1;
    lemma addition_inequality: \forall integer a, b; a < b ==> a < b + 1;
    
    predicate axiom_inequality_transitive(integer a, integer b, integer c) = 
        (a < b && b < c) ==> a < c;
    lemma inequality_transitive: \forall integer a, b, c; (a < b && b < c) ==> a < c;
    
    predicate calc_example_1_pre = 1 < 5 && 5 < 9 && 9 < 12;
    predicate calc_example_1_post = 1 < 12;
    lemma calc_example_1: calc_example_1_pre ==> calc_example_1_post;
*/

/*@
    requires \true;
    ensures \true;
*/
int main() {
    int a;
    int b;
    int c;
    
    //@ assert 1 < 5;
    //@ assert 5 < 9;
    //@ assert 9 < 12;
    //@ assert 1 < 12;
    
    return 0;
}
