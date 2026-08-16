/*@
    predicate strictly_increasing(integer A, integer B, integer C) =
        A < B && B < C;
*/

/*@
    lemma calc_example_u_lemma:
        \forall integer a, b;
            a <= b + 1 ==> a + 2 <= b + 3;
*/

/*@
    lemma calc_example_l_lemma:
        \forall integer a, b;
            a + 1 >= b ==> a + 2 >= b + 1;
*/

/*@
    lemma is_strictly_increasing_lemma:
        \forall integer A, B, C;
            strictly_increasing(A, B, C) ==> A < C;
*/

/*@
    lemma check_relatives_lemma:
        \forall integer A, B, C;
            strictly_increasing(A, B, C) ==> A < C;
*/

/*@
    requires \true;
    assigns \nothing;
*/
void main() {
    int A;
    int B;
    int C;
    
    //@ ghost int a = 0;
    //@ ghost int b = 0;
    
    // Example usage of calc_example_u lemma
    //@ assert a <= b + 1;
    //@ assert a + 2 <= b + 3;
    
    // Example usage of calc_example_l lemma
    //@ assert a + 1 >= b;
    //@ assert a + 2 >= b + 1;
    
    // Example usage of is_strictly_increasing lemma
    A = 1;
    B = 2;
    C = 3;
    //@ assert strictly_increasing(A, B, C);
    //@ assert A < C;
    
    // Example usage of check_relatives lemma
    //@ assert strictly_increasing(A, B, C);
    //@ assert A < C;
}
