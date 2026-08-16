/*@
    predicate reflexive(integer x) = x == x;
    predicate symmetric(integer a, integer b) = a == b ==> b == a;
    predicate transitive(integer a, integer b, integer c) = (a == b && b == c) ==> a == c;
    predicate monotonic(integer a, integer b) = a <= b ==> a <= b;
    predicate strict_monotonic(integer a, integer b) = a < b ==> a < b;
    predicate transitive_monotonic(integer a, integer b, integer c) = (a <= b && b <= c) ==> a <= c;
    predicate transitive_strict_monotonic(integer a, integer b, integer c) = (a < b && b < c) ==> a < c;
    predicate symmetric_monotonic(integer a, integer b) = a <= b ==> b >= a;
    predicate symmetric_strict_monotonic(integer a, integer b) = a < b ==> b > a;
    predicate transitive_symmetric_monotonic(integer a, integer b, integer c) = (a <= b && b <= c) ==> c >= a;
    predicate transitive_symmetric_strict_monotonic(integer a, integer b, integer c) = (a < b && b < c) ==> c > a;

    lemma calc_example_8: \forall integer x, y; x == y ==> x * 2 == y * 2;
    lemma assert_transitivity: \forall integer a, b, c; (a == b && b == c) ==> a == c;
    lemma assert_reflexivity: \forall integer x; x == x ==> x == x;
    lemma assert_symmetry: \forall integer a, b; a == b ==> b == a;
    lemma assert_substitution: \forall integer a, b, c; (a == b && b == c) ==> a == c;
    lemma assert_transitive_property: \forall integer a, b, c; (a <= b && b <= c) ==> a <= c;
    lemma assert_monotonicity: \forall integer a, b; a <= b ==> a <= b;
    lemma assert_monotonicity_property: \forall integer a, b, c; (a <= b && b <= c) ==> a <= c;
    lemma assert_strict_monotonicity: \forall integer a, b; a < b ==> a < b;
    lemma assert_strict_monotonicity_property: \forall integer a, b, c; (a < b && b < c) ==> a < c;
    lemma assert_monotonicity_and_transitivity: \forall integer a, b, c; (a <= b && b <= c) ==> a <= c;
    lemma assert_strict_monotonicity_and_transitivity: \forall integer a, b, c; (a < b && b < c) ==> a < c;
    lemma assert_monotonicity_and_symmetry: \forall integer a, b; a <= b ==> b >= a;
    lemma assert_strict_monotonicity_and_symmetry: \forall integer a, b; a < b ==> b > a;
    lemma assert_monotonicity_property_and_symmetry: \forall integer a, b, c; (a <= b && b <= c) ==> c >= a;
    lemma assert_strict_monotonicity_property_and_symmetry: \forall integer a, b, c; (a < b && b < c) ==> c > a;
*/

/*@
    requires x == y;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_8(int x, int y) {
    //@ assert x * 2 == y * 2;
    return 1;
}

/*@
    requires a == b && b == c;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_transitivity(int a, int b, int c) {
    //@ assert a == c;
    return 1;
}

/*@
    requires x == x;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_reflexivity(int x) {
    //@ assert x == x;
    return 1;
}

/*@
    requires a == b;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_symmetry(int a, int b) {
    //@ assert b == a;
    return 1;
}

/*@
    requires a == b && b == c;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_substitution(int a, int b, int c) {
    //@ assert a == c;
    return 1;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_transitive_property(int a, int b, int c) {
    //@ assert a <= c;
    return 1;
}

/*@
    requires a <= b;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_monotonicity(int a, int b) {
    //@ assert a <= b;
    return 1;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_monotonicity_property(int a, int b, int c) {
    //@ assert a <= c;
    return 1;
}

/*@
    requires a < b;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_strict_monotonicity(int a, int b) {
    //@ assert a < b;
    return 1;
}

/*@
    requires a < b && b < c;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_strict_monotonicity_property(int a, int b, int c) {
    //@ assert a < c;
    return 1;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_monotonicity_and_transitivity(int a, int b, int c) {
    //@ assert a <= c;
    return 1;
}

/*@
    requires a < b && b < c;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_strict_monotonicity_and_transitivity(int a, int b, int c) {
    //@ assert a < c;
    return 1;
}

/*@
    requires a <= b;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_monotonicity_and_symmetry(int a, int b) {
    //@ assert b >= a;
    return 1;
}

/*@
    requires a < b;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_strict_monotonicity_and_symmetry(int a, int b) {
    //@ assert b > a;
    return 1;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_monotonicity_property_and_symmetry(int a, int b, int c) {
    //@ assert c >= a;
    return 1;
}

/*@
    requires a < b && b < c;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_strict_monotonicity_property_and_symmetry(int a, int b, int c) {
    //@ assert c > a;
    return 1;
}

int main() {
    return 0;
}
