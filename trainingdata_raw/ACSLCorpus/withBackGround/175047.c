/*@
    predicate non_negative(integer x) = x >= 0;
    predicate bounded_increment(integer x) = x <= x + 5;

    lemma calc_example_bb: \forall integer x; non_negative(x) ==> bounded_increment(x);
*/

/*@
    requires non_negative(x);
    ensures bounded_increment(x);
*/
void calc_example_bb(int x) {
    // Variable declarations at scope top
    int y;

    y = 3;

    //@ assert x >= 0;
    //@ assert y == 3;
    //@ assert x <= x + 5;
}

int main() {
    return 0;
}
