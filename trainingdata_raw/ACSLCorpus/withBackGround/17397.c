/*@
predicate strict_transitivity(integer a, integer b, integer c) =
    a < b && b < c ==> a < c;

lemma strict_transitivity_lemma:
    \forall integer a, b, c; a < b && b < c ==> a < c;

lemma nonlinear_transitivity_lemma:
    \forall integer a, b, c; a < b && b < c ==> a < c;
*/

/*@
requires a < b && b < c;
ensures \result == 0;
*/
int lemma_strict_transitivity(int a, int b, int c) {
    //@ assert a < b;
    //@ assert b < c;
    //@ assert a < c;
    return 0;
}

/*@
requires a < b && b < c;
ensures \result == 0;
*/
int lemma_nonlinear_transitivity(int a, int b, int c) {
    //@ assert a < b;
    //@ assert b < c;
    //@ assert a < c;
    return 0;
}

int main() {
    return 0;
}
