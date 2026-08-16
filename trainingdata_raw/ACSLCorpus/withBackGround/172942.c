/*@
    predicate a_plus_b_le_20(integer a, integer b) = a + b <= 20;
    predicate a_le_b(integer a, integer b) = a <= b;
    
    lemma calc_example_5: \forall integer a, b; a <= 10 && b <= 10 ==> a_plus_b_le_20(a, b);
    lemma calc_example_6: \forall integer a, b; a == b ==> a_le_b(a, b);
    lemma calc_example_7: \forall integer a, b; a <= b ==> a_le_b(a, b);
*/

int main() {
    int a;
    int b;
    
    //@ ghost int a_ghost = 5;
    //@ ghost int b_ghost = 5;
    
    //@ assert a_plus_b_le_20(a_ghost, b_ghost);
    //@ assert a_le_b(a_ghost, b_ghost);
    
    return 0;
}
