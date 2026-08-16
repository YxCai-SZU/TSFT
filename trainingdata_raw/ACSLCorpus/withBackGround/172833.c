/*@
    predicate left_shift_commutative(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100 ==> a + b == b + a;

    predicate right_shift_commutative(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100 ==> a * b == b * a;

    predicate associativity(integer a, integer b, integer c) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 ==> a * (b * c) == (a * b) * c;

    predicate distributivity(integer a, integer b, integer c) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 ==> a * (b + c) == a * b + a * c;

    lemma division_left_shifting: \forall integer a, b; left_shift_commutative(a, b);
    lemma division_right_shifting: \forall integer a, b; right_shift_commutative(a, b);
    lemma division_associativity: \forall integer a, b, c; associativity(a, b, c);
    lemma division_distributivity: \forall integer a, b, c; distributivity(a, b, c);
*/

int main() {
    int a;
    int b;
    int c;
    
    //@ assert left_shift_commutative(5, 10);
    //@ assert right_shift_commutative(5, 10);
    //@ assert associativity(2, 3, 4);
    //@ assert distributivity(2, 3, 4);
    
    return 0;
}
