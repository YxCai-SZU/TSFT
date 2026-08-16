/*@
    predicate addition_axiom(integer x) = x + 0 == x;
    predicate subtraction_axiom(integer x) = x - 0 == x;
    predicate equality_implies_addition(integer x, integer y) = x == y ==> x + 0 == y;
    predicate equality_implies_subtraction(integer x, integer y) = x == y ==> x - 0 == y;

    lemma axiom_addition: \forall integer x; addition_axiom(x);
    lemma axiom_subtraction: \forall integer x; subtraction_axiom(x);
    lemma axiom_addition_strict: \forall integer x, y; x == y ==> x + 0 == y;
    lemma axiom_subtraction_strict: \forall integer x, y; x == y ==> x - 0 == y;
*/

/*@
    requires x == y;
    ensures \result == y;
*/
int calc_example_7(int x, int y) {
    //@ assert x + 0 == y;
    return x + 0;
}

/*@
    requires x == y;
    ensures \result == y;
*/
int calc_example_8(int x, int y) {
    //@ assert x - 0 == y;
    return x - 0;
}

/*@
    requires x == y;
    ensures \result == y;
*/
int calc_example_7_strict(int x, int y) {
    //@ assert x + 0 == y;
    return x + 0;
}

/*@
    requires x == y;
    ensures \result == y;
*/
int calc_example_8_strict(int x, int y) {
    //@ assert x - 0 == y;
    return x - 0;
}

int main() {
    return 0;
}
