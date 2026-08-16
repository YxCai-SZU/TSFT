/*@
    predicate non_negative(integer x) = x >= 0;
    lemma arithmetic_chain: \forall integer x; non_negative(x) ==> x + 2 <= x + 4 <= x + 6 <= x + 8;
*/

/*@
    requires non_negative(x);
    ensures \result == 0;
*/
int calc_arithmetic_example_1(int x) {
    //@ assert x + 2 <= x + 4;
    //@ assert x + 4 <= x + 6;
    //@ assert x + 6 <= x + 8;
    return 0;
}

int main() {
    return 0;
}
