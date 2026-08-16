/*@
    predicate addition_commutative(integer a, integer b) = a + b == b + a;
    predicate addition_associative(integer a, integer b, integer c) = (a + b) + c == a + (b + c);
    predicate multiplication_commutative(integer a, integer b) = a * b == b * a;
    predicate distributive(integer a, integer b, integer c) = a * (b + c) == a * b + a * c;
    predicate multiply_three(integer a) = a * 3 == 3 * a;
    predicate linear_arithmetic(integer a, integer b, integer c) = 3 * a + b * c == a * 3 + c * b;
*/

/*@
    lemma addition_is_commutative: \forall integer a, b; addition_commutative(a, b);
    lemma addition_is_associative: \forall integer a, b, c; addition_associative(a, b, c);
    lemma multiplication_is_commutative: \forall integer a, b; multiplication_commutative(a, b);
    lemma distributive_property: \forall integer a, b, c; a >= 0 && b >= 0 && c >= 0 ==> distributive(a, b, c);
    lemma multiply_three_property: \forall integer a; a >= 0 && a <= 10 ==> multiply_three(a);
    lemma verify_linear_arithmetic: \forall integer a, b, c; 
        a >= 0 && b >= 0 && c >= 0 && a <= 10 && b <= 10 && c <= 10 ==> linear_arithmetic(a, b, c);
*/

int main() {
    int a;
    int b;
    int c;
    
    //@ assert addition_commutative(5, 3);
    //@ assert addition_associative(1, 2, 3);
    //@ assert multiplication_commutative(4, 7);
    //@ assert distributive(2, 3, 4);
    //@ assert multiply_three(5);
    //@ assert linear_arithmetic(2, 3, 4);
    
    return 0;
}
