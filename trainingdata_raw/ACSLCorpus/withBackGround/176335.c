/*@
    predicate less_than(integer x, integer y) = x < y;
    predicate greater_than_or_equal(integer x, integer y) = x >= y;
    predicate less_than_or_equal(integer x, integer y) = x <= y;
    predicate equal(integer x, integer y) = x == y;

    lemma calc_example_5:
        \forall integer x, y; x < y ==> x + 2 < y + 3;

    lemma greater_than_or_equal_to:
        \forall integer x, y; x >= y ==> x >= y;

    lemma less_than_or_equal_to:
        \forall integer x, y; x <= y ==> x <= y;

    lemma equal_to:
        \forall integer x, y; x == y ==> x == y;
*/

/*@
    requires x < y;
    ensures \result == 0;
*/
int calc_example_5(int x, int y) {
    //@ assert x < y;
    //@ assert x + 2 < y + 2;
    //@ assert y + 2 < y + 3;
    //@ assert x + 2 < y + 3;
    return 0;
}

/*@
    requires x >= y;
    ensures \result == 0;
*/
int greater_than_or_equal_to(int x, int y) {
    //@ assert x >= y;
    return 0;
}

/*@
    requires x <= y;
    ensures \result == 0;
*/
int less_than_or_equal_to(int x, int y) {
    //@ assert x <= y;
    return 0;
}

/*@
    requires x == y;
    ensures \result == 0;
*/
int equal_to(int x, int y) {
    //@ assert x == y;
    return 0;
}

int main() {
    return 0;
}
