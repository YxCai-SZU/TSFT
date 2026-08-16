/*@
    predicate equal(integer a, integer b) = a == b;
    predicate less_equal(integer a, integer b) = a <= b;

    logic integer plus_one_minus_one(integer n) = n + 1 - 1;

    lemma lemma1: \forall integer x; equal(x, x) ==> equal(x, plus_one_minus_one(x));
    lemma lemma2: \forall integer x, y; equal(x, y) ==> equal(x, plus_one_minus_one(y));
    lemma lemma3: \forall integer x, y; less_equal(x, y) ==> less_equal(x, plus_one_minus_one(y));
    lemma lemma4: \forall integer x, y; less_equal(x, plus_one_minus_one(y)) ==> less_equal(x, y);
*/

/*@
    requires x == x;
    ensures \result == 0;
*/
int lemma1_impl(int x) {
    //@ assert x == x;
    //@ assert x == x + 1 - 1;
    return 0;
}

/*@
    requires x == y;
    ensures \result == 0;
*/
int lemma2_impl(int x, int y) {
    //@ assert x == y;
    //@ assert y == y + 1 - 1;
    //@ assert x == y + 1 - 1;
    return 0;
}

/*@
    requires x <= y;
    ensures \result == 0;
*/
int lemma3_impl(int x, int y) {
    //@ assert x <= y;
    //@ assert y <= y + 1 - 1;
    //@ assert x <= y + 1 - 1;
    return 0;
}

/*@
    requires x <= y + 1 - 1;
    ensures \result == 0;
*/
int lemma4_impl(int x, int y) {
    //@ assert x <= y + 1 - 1;
    //@ assert y + 1 - 1 <= y;
    //@ assert x <= y;
    return 0;
}

int main() {
    return 0;
}
