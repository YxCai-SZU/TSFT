/*@
    requires (\exists integer j; ((j) * 2) == (i));
    ensures \result % 2 == 0;
*/
int test_exists_f_wrapper(int i) {
    //@ assert (\exists integer j; ((j) * 2) == (i));
    //@ assert i % 2 == 0;
    return i;
}

/*@
    requires (\exists integer j; ((j) * 2) == (i));
    ensures \result % 2 == 0;
*/
int test_exists_f2_wrapper(int i) {
    //@ assert (\exists integer j; ((j) * 2) == (i));
    //@ assert i % 2 == 0;
    return i;
}

/*@
    requires (\exists integer j; ((j) * 2) == (i));
    ensures \result % 2 == 0;
*/
int lemma_f_implies_even_wrapper(int i) {
    //@ assert (\exists integer j; ((j) * 2) == (i));
    //@ assert i % 2 == 0;
    return i;
}

int main() {
    return 0;
}
