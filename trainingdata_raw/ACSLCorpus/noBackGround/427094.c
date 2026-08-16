/*@
    requires ((i) % 2 == 0) && i > 0;
    ensures ((((i)) % 2 == 0) && (i) > 0);
*/
void lemma_even_f(int i) {
    //@ assert ((((i)) % 2 == 0) && (i) > 0);
}

/*@
    ensures \forall integer i; ((i) % 2 == 0) && i > 0 ==> ((((i)) % 2 == 0) && (i) > 0);
*/
void test_even_f() {
    int i;
    /*@
        loop invariant 0 <= i <= 101;
        loop invariant \forall integer j; 0 <= j < i && ((j) % 2 == 0) && j > 0 ==> ((((j)) % 2 == 0) && (j) > 0);
        loop assigns i;
    */
    for (i = 0; i <= 100; i++) {
        if (i % 2 == 0 && i > 0) {
            //@ assert ((((i)) % 2 == 0) && (i) > 0);
        }
    }
}

int main() {
    test_even_f();
    return 0;
}
