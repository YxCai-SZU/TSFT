/*@
    predicate div_by_3(integer x) = x % 3 == 0;

    lemma lemma_div_by_3:
        \forall integer i; div_by_3(i) ==> i % 3 == 0;

    lemma test_div_by_3:
        \forall integer i; div_by_3(i) ==> i % 3 == 0;
*/

/*@
    requires div_by_3(i);
    ensures \result == 0;
*/
int check_div_by_3(int i) {
    //@ assert i % 3 == 0;
    return i % 3;
}

int main() {
    return 0;
}
